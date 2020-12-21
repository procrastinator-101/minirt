/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:07:18 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/21 17:10:29 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "X.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

# include "keys.h"
# include "libft/libft.h"
# include "lib_3d_math/lib_3d_math.h"
# include "get_next_line/get_next_line.h"
# include "objects_intersections/intersection.h"
# include "support_functions/support_functions.h"
# include "configuration_reader/configuration_reader.h"

# define AMPLITUDE			5
# define WAVE_LENGTH		5
# define ROTATION_ANGLE		9

typedef struct	s_bitmap
{
	unsigned	bpp;
	unsigned	width;
	unsigned	height;
	unsigned	line_size;
	char		*pixel_data;
}				t_bitmap;


void			check_prog_arg(int argc, char **argv, int *file_index);

int				initialise_display(t_display *display, void **entities);
int				initialise_image_customizers(void **entities);
void			user_interract(void **entities, t_display *display);

int				raytracer(t_camera *camera, void **entities, t_display *display);
void			render_block(void **entities, t_camera *camera, int start, int end);
t_coord_3d		get_left_corner(t_camera *camera, t_screen screen);

unsigned		render_pixel(void **entities, t_camera *camera, t_ray ray);

t_rgb			get_color(t_ray ray, void **entities);


int				image_to_bmp(t_bitmap bitmap, int fd);
void			save_image(void **entities, char *image_name, char *image);

void			update_pixel_data(t_display *display, int x, int y, unsigned color);

void			ft_btl_endian(unsigned char *src, int bit_offset, int size);

/**************************** user interaction utilities ***************************/

int				terminate_minirt(void *param);
int				manage_key(int key, void *param);
int				manage_mouse_hits(int button, int x, int y, void *param);
int				manage_mouse_moves(int x, int y, void *param);


void			manage_translation(int key, t_camera *camera, void **entities);
void			manage_rotation(int key, t_camera *camera, void **entities);

void			translate_object(void *object, t_coord_3d v, int type);
void			translate_camera(t_camera *camera, t_coord_3d v);
void			translate_light(t_light *light, t_coord_3d v);
void			translate_sphere(t_sphere *sphere, t_coord_3d v);
void			translate_plane(t_plane *plane, t_coord_3d v);
void			translate_square(t_square *square, t_coord_3d v);
void			translate_cylinder(t_cylinder *cylinder, t_coord_3d v);
void			translate_triangle(t_triangle *triangle, t_coord_3d v);
void			translate_cone(t_cone *cone, t_coord_3d v);
void			translate_cube(t_cube *cube, t_coord_3d v);
void			translate_pyramid(t_pyramid *pyramid, t_coord_3d v);
void			translate_skybox(t_skybox *skybox, t_camera *camera);

t_smat_3d		get_rotation_matrix(int angle, t_coord_3d n);

void			rotate_object(void *object, t_smat_3d m, int type);
void			rotate_camera(t_camera *camera, t_smat_3d m);
void			rotate_plane(t_plane *plane, t_smat_3d m);
void			rotate_square(t_square *square, t_smat_3d m);
void			rotate_cylinder(t_cylinder *cylinder, t_smat_3d m);
void			rotate_triangle(t_triangle *triangle, t_smat_3d m);
void			rotate_cone(t_cone *cone, t_smat_3d m);
void			rotate_cube(t_cube *cube, t_smat_3d m);
void			rotate_pyramid(t_pyramid *pyramid, t_smat_3d m);




int				rgb_cmp(t_rgb a, t_rgb b, double margin);
unsigned		rgb_to_uint(t_rgb rgb);
t_rgb			uint_to_rgb(unsigned color);
t_rgb			rgb_to_sepia(t_rgb rgb);
t_rgb			rgb_sum(t_rgb a, t_rgb b);
t_rgb			rgb_mul_rgb(t_rgb a, t_rgb b);
t_rgb			rgb_mul_double(t_rgb rgb, double n);
t_rgb			get_black_rgb(void);
t_rgb			adjust_rgb(t_rgb rgb);
t_rgb			get_map_pix_color(t_map *map, double x, double y);

int				get_rgb_nb(double x, double y, double grid_len);
t_rgb			get_object_rgb(void *object, t_coord_3d p, int type);
t_rgb			get_rgb_sphere(t_sphere *sphere, t_coord_3d p);
t_rgb			get_rgb_plane(t_plane *plane, t_coord_3d p);
t_rgb			get_rgb_square(t_square *square, t_coord_3d p);
t_rgb			get_rgb_cylinder(t_cylinder *cylinder, t_coord_3d p);
t_rgb			get_rgb_triangle(t_triangle *triangle, t_coord_3d p);
t_rgb			get_rgb_cone(t_cone *cone, t_coord_3d p);


t_rgb			illuminate(t_intersection hit, void **entities, t_ray ray);
t_rgb			ambient_term(t_ambient *ambient);

int				is_light_blocked(t_ray ray, void **entities);
t_rgb			diffuse_spec_terms(t_ray l, t_coord_3d n, t_coord_3d v, t_light *light);

t_coord_3d		surface_normal(void *object, t_coord_3d d, t_coord_3d p, int type);
t_coord_3d		sphere_normal(t_sphere *sphere, t_coord_3d p, t_coord_3d d);
t_coord_3d		plane_normal(t_plane *plane, t_coord_3d p, t_coord_3d d);
t_coord_3d		square_normal(t_square *square, t_coord_3d p, t_coord_3d d);
t_coord_3d		cylinder_normal(t_cylinder *cylinder, t_coord_3d p, t_coord_3d d);
t_coord_3d		triangle_normal(t_triangle *triangle, t_coord_3d p, t_coord_3d d);
t_coord_3d		cone_normal(t_cone *cone, t_coord_3d p, t_coord_3d d);
t_coord_3d		get_bump_normal(t_map *bump_map, t_3d_basis *basis, t_coord_3d n, \
				t_coord_3d p);
t_coord_3d		get_wave_normal(t_3d_basis basis, t_coord_3d n, t_coord_3d c, \
				t_coord_3d p);

#endif
