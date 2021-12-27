/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_reader.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:27:58 by yarroubi          #+#    #+#             */
/*   Updated: 2021/02/24 16:59:46 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGURATION_READER_H
# define CONFIGURATION_READER_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# include "../external_includes/mlx.h"
# include "errors.h"
# include "libft.h"
# include "lib_3d_math.h"
# include "get_next_line.h"
# include "support_functions.h"

# define ENTITIES_SIZE						26

/*
**=============				entities indexes defines			  =============
*/
# define RESOLUTION							1
# define AMBIENT							2
# define CAMERA								3
# define LIGHT								4
# define SPHERE								5
# define PLANE								6
# define SQUARE								7
# define CYLINDER							8
# define TRIANGLE							9
# define CONE								10
# define DISK								11
# define RECTANGLE							12
# define CUBE								13
# define PYRAMID							14
# define SKYBOX								15
# define SEPIA								16
# define ANTI_ALIASING						17
# define DISPLAY							18
# define USER_CAMERA						19
# define USER_LIGHT							20
# define USER_OBJECT						21
# define USER_OBJECT_TYPE					22
# define SAVE_IMAGE							23
# define RENDER								24
# define MUTEXES							25

/*
**=============				texture types defines			  	  =============
*/
# define WAVE								'w'
# define BUMP_MAP							'b'
# define RGB								'r'
# define CHECKERBOARD						'c'
# define UV_MAP								'm'

/*
**=============						other defines			  	  =============
*/
# define MAX_AA_FACTOR						10
# define STATIC_MODE						's'
# define INTERACTIVE_MODE					'i'
# define LINEAR_INTERPOLATION				0
# define PLANE_TILTING_SIZE					100

/*
**=============				basic data types definitions		  =============
*/
typedef struct				s_rgb
{
	double					red;
	double					green;
	double					blue;
}							t_rgb;

typedef struct				s_screen
{
	t_coord_3d				u;
	t_coord_3d				v;
	t_coord_3d				w;
	double					width;
	double					height;
}							t_screen;

typedef struct				s_pixel
{
	double					width;
	double					height;
	t_coord_3d				u;
	t_coord_3d				v;
}							t_pixel;

typedef struct				s_map
{
	double					width;
	double					height;
	double					u_scale;
	double					v_scale;
	char					*img_addr;
	void					*img_ptr;
	int						bpp;
	int						line_size;
}							t_map;

typedef struct				s_texture
{
	double					width;
	double					height;
	double					grid_len;
	t_rgb					rgb1;
	t_rgb					rgb2;
	t_map					uv_map;
	t_map					bump_map;
	char					type[2];
}							t_texture;

/*
**=============				scene parameters definitions		  =============
*/
typedef struct				s_resolution
{
	int						width;
	int						height;
}							t_resolution;

typedef struct				s_ambient
{
	double					ratio;
	t_rgb					rgb;
}							t_ambient;

typedef struct				s_camera
{
	t_pixel					pixel;
	t_pixel					sub_pixel;
	t_screen				screen;
	t_coord_3d				position;
	struct s_camera			*previous;
	struct s_camera			*next;
	int						fov;
}							t_camera;

typedef struct				s_light
{
	double					brightness;
	t_rgb					rgb;
	t_coord_3d				position;
	struct s_light			*previous;
	struct s_light			*next;
}							t_light;

/*
**=============				prime ojects definitions			  =============
*/
typedef struct				s_sphere
{
	double					radius;
	t_3d_basis				basis;
	t_coord_3d				center;
	struct s_sphere			*next;
	t_texture				texture;
	char					mode;
}							t_sphere;

typedef	struct				s_plane
{
	t_3d_basis				basis;
	t_coord_3d				position;
	struct s_plane			*next;
	t_texture				texture;
}							t_plane;

typedef struct				s_square
{
	double					radius;
	t_3d_basis				basis;
	t_coord_3d				position;
	void					*parent;
	struct s_square			*next;
	t_texture				texture;
	int						parent_type;
	int						face_number;
}							t_square;

typedef struct				s_cylinder
{
	double					radius;
	double					height;
	t_coord_3d				position;
	t_3d_basis				basis;
	struct s_cylinder		*next;
	t_texture				texture;
	int						caps;
}							t_cylinder;

typedef struct				s_triangle
{
	t_3d_basis				basis;
	t_coord_3d				c;
	t_coord_3d				p1;
	t_coord_3d				p2;
	t_coord_3d				p3;
	t_coord_3d				centroid;
	void					*parent;
	struct s_triangle		*next;
	t_texture				texture;
}							t_triangle;

typedef struct				s_cone
{
	double					angle;
	double					height;
	t_3d_basis				basis;
	t_coord_3d				vertex;
	struct s_cone			*next;
	t_texture				texture;
}							t_cone;

typedef struct				s_disk
{
	double					radius;
	t_3d_basis				basis;
	t_coord_3d				center;
	struct s_disk			*next;
	t_texture				texture;
}							t_disk;

typedef struct				s_rectangle
{
	double					width;
	double					height;
	t_3d_basis				basis;
	t_coord_3d				position;
	void					*parent;
	struct s_rectangle		*next;
	t_texture				texture;
	int						parent_type;
	int						face_number;
}							t_rectangle;

/*
**=============				compound ojects definitions			  =============
*/
typedef struct				s_cube
{
	double					radius;
	t_3d_basis				basis;
	t_coord_3d				center;
	t_square				*faces[6];
	struct s_cube			*next;
	t_texture				texture;
}							t_cube;

typedef struct				s_pyramid
{
	t_coord_3d				apex;
	t_square				*base;
	t_triangle				*faces[4];
	struct s_pyramid		*next;
	t_texture				texture;
}							t_pyramid;

typedef struct				s_hyperrectangle
{
	double					width;
	double					height;
	t_3d_basis				basis;
	t_coord_3d				center;
	t_rectangle				*faces[6];
	struct s_hyperrectangle	*next;
	t_texture				texture;
}							t_hyperrectangle;

typedef	struct				s_skybox
{
	t_square				faces[6];
}							t_skybox;

/*
**=============					filters definitions				  =============
*/
typedef struct				s_sepia
{
	char					on;
}							t_sepia;

typedef struct				s_anti_aliasing
{
	int						factor;
}							t_anti_aliasing;

/*
**=============					display definition			  	  =============
*/
typedef struct				s_display
{
	void					*mlx_ptr;
	void					*win_ptr;
	void					*img_ptr;
	void					*img_addr;
	int						bpp;
	int						local_endian;
	int						server_endian;
	int						line_size;
}							t_display;

/*
**=============				non specific functions				  =============
*/
int							check_critical_entities(void **entities);
void						get_screen_pixel(void **entities);
void						ft_get_screen_size(int *width, int *height);
void						destroy_entities(void **entities);
void						parse_configuration(void **entities, int fd);
void						configuration_reader(char *input_file, void **entities);

/*
**=============					parsing	 functions				  =============
*/
int							update_start(char *line, int start);
int							find_next_arg(char *line, int start);
int							check_end_entity_info(char *line, int start, int ret);
int							get_entity_info(char *line, void **entities);

/*
**=============					fetching functions				  =============
*/
int							get_radius(char *line, double *radius, int start);
int							fetch_rgb(char *line, t_rgb *rgb, int start);
int							fetch_point_3d(char *line, t_coord_3d *point, \
							int start);
int							fetch_vector_3d(char *line, t_coord_3d *vector, \
							int start);

/*
**=============					linked lists functions			  =============
*/
void						ft_lst_add_head(void **lst_tail, void *new, int type);
void						ft_lst_destroy(void **lst_tail, int type, \
							t_display *display);
void						ft_dclst_add_head(void **lst_tail, void *new, int type);
void						ft_dclst_destroy(void **tail, int type);
void						*get_next_lst_mem(void *lst_mem, int type);
void						*get_previous_lst_mem(void *lst_mem, int type);
void						ft_update_next(void *lst_mem, void *next, int type);
void						ft_update_previous(void *lst_mem, void *previous, \
							int type);
void						ft_destroy_lst_mem(void *lst_mem, int type, \
							t_display *display);
t_texture					*get_lst_mem_texture(void *lst_mem, int type);

/*
**=============					texture functions			  	  =============
*/
int							get_texture(char *line, t_texture *texture, \
							t_display *display, int type);
int							get_texture_color(char *line, t_texture *texture, \
							int start);
int							get_texture_type(char *line, char *texture_type, \
							int start);
int							get_texture_map(char *line, t_map *map, \
							t_display *display, int start);

void						initialise_map_dimension(t_texture *texture);
void						get_triangle_basis(t_triangle *triangle);
void						prepare_triangle_mapping(t_triangle *triangle);
void						get_triangle_texture_center(t_triangle *triangle);

/*
**=============				scene parameters functions			  =============
*/
int							get_resolution(char *line, void **entities);
int							get_ambient_light(char *line, void **entities);
int							get_camera(char *line, void **entities);
int							get_light(char *line, void **entities);

/*
**=============				prime objects functions				  =============
*/
int							get_sphere(char *line, void **entities);
int							get_plane(char *line, void **entities);
int							get_square(char *line, void **entities);
int							get_cylinder(char *line, void **entities);
int							get_triangle(char *line, void **entities);
int							get_cone(char *line, void **entities);
int							get_disk(char *line, void **entities);
int							get_rectangle(char *line, void **entities);

/*
**=============					cube functions					  =============
*/
int							get_cube(char *line, void **entities);
int							build_cube(t_cube *cube, void **entities);
int							construct_cubes(t_cube *tail, void **entities);
void						build_cube_faces(t_square *faces[6], t_coord_3d \
							position, double radius, t_coord_3d *base);

/*
**=============					pyramid functions				  =============
*/
int							get_pyramid(char *line, void **entities);
int							build_pyramid(t_pyramid *pyramid, void **entities);
int							construct_pyramids(t_pyramid *tail, void **entities);
void						build_pyramid_faces(t_pyramid *pyramid, double radius, \
							t_coord_3d center);

int							get_skybox(char *line, void **entities);
int							get_sepia(char *line, void **entities);
int							get_anti_aliasing(char *line, void **entities);

#endif
