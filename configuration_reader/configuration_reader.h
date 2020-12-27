/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_reader.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:27:58 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/27 12:28:30 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGURATION_READER_H
# define CONFIGURATION_READER_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>//to elimiante
# include <stdlib.h>
# include <limits.h>

# include "../mlx.h"
# include "../libft/libft.h"
# include "../lib_3d_math/lib_3d_math.h"
# include "../get_next_line/get_next_line.h"
# include "../support_functions/support_functions.h"

# define ENTITIES_SIZE						24

# define EFR								15	//FILE_READING_ERROR
# define EMA								16	//MEMORY_ALLOCATION_FAILURE
# define EMRD								17	//MULTIPLE_R_DECLARATION
# define EMAD								18	//MULTIPLE_A_DECLARATION
# define EERP								19	//EMPTY_RESOLUTION
# define EEAP								20	//EMPTY_AMBIENT
# define EECP								21	//EMPTY_CAMERA
# define EMC								22	//MLX_CONNECTION_ERROR
# define EWC								23	//WINDOW_CREATION_ERROR
# define EIC								24	//IMAGE_CREATION_ERROR
# define EMFE								25	//MISSING FILE EXTENSION
# define EWFE								26	//WRONG FILE EXTENSION
# define EMIF								27	//MISSING INPUT FILE
# define EUPA								28	//UNDESIRED PROGRAM ARGUMENTS
# define EIA								29	//INVALID ARGUMENT

# define RESOLUTION							1
# define AMBIENT							2
# define CAMERA								3
# define LIGHT								4
# define SPHERE								5
# define PLANE								6
# define SQUARE								7
# define CYLINDER							8
# define TRIANGLE							9
# define RECTANGLE							10
# define CONE								11
# define CUBE								12
# define PYRAMID							13
# define SKYBOX								14
# define SEPIA								15
# define ANTI_ALIASING						16
# define DISPLAY							17
# define USER_CAMERA						18
# define USER_LIGHT							19
# define USER_OBJECT						20
# define USER_OBJECT_TYPE					21
# define SAVE_IMAGE							22
# define RENDER								23


# define WAVE								'w'
# define BUMP_MAP							'b'
# define RGB								'r'
# define CHECKERBOARD						'c'
# define UV_MAP								'm'

# define MAX_AA_FACTOR						10
# define STATIC_MODE						's'
# define INTERACTIVE_MODE					'i'

# define LINEAR_INTERPOLATION				0
# define PLANE_TILTING_SIZE					100
/************** basic data structures **************/

typedef struct			s_rgb
{
	double				red;
	double				green;
	double				blue;
}						t_rgb;

typedef struct			s_3d_basis
{
	t_coord_3d			u;
	t_coord_3d			v;
	t_coord_3d			w;
}						t_3d_basis;

typedef struct			s_screen
{
	t_coord_3d			u;
	t_coord_3d			v;
	t_coord_3d			w;
	double				width;
	double				height;
}						t_screen;

typedef struct			s_pixel
{
	double				width;
	double				height;
	t_coord_3d			u;
	t_coord_3d			v;
}						t_pixel;

typedef struct			s_map
{
	double				width;
	double				height;
	double				u_scale;
	double				v_scale;
	char				*img_addr;
	void				*img_ptr;
	int					bpp;
	int					line_size;
}						t_map;

typedef struct			s_texture
{
	double				width;
	double				height;
	double				grid_len;
	t_rgb				rgb1;
	t_rgb				rgb2;
	t_map				uv_map;
	t_map				bump_map;
	char				type[2];
}						t_texture;

/************ entities' data structures ***********/

typedef struct			s_resolution
{
	int					width;
	int					height;
}						t_resolution;

typedef struct			s_ambient
{
	double				ratio;
	t_rgb				rgb;
}						t_ambient;

typedef struct			s_camera
{
	t_pixel				pixel;
	t_pixel				sub_pixel;
	t_screen			screen;
	t_coord_3d			position;
	struct s_camera		*previous;
	struct s_camera		*next;
	int					fov;
}						t_camera;

typedef struct			s_light
{
	double				brightness;
	t_rgb				rgb;
	t_coord_3d			position;
	struct s_light		*previous;
	struct s_light		*next;
}						t_light;

typedef struct			s_sphere
{
	double				radius;
	t_3d_basis			basis;
	t_coord_3d			center;
	struct s_sphere		*next;
	t_texture			texture;
	char				mode;
}						t_sphere;

typedef	struct			s_plane
{
	t_3d_basis			basis;
	t_coord_3d			position;
	struct s_plane		*next;
	t_texture			texture;
}						t_plane;

typedef struct			s_square
{
	double				radius;
	t_3d_basis			basis;
	t_coord_3d			position;
	void				*parent;
	struct s_square		*next;
	t_texture			texture;
	int					parent_type;
	int					face_number;
}						t_square;

typedef struct			s_cylinder
{
	double				radius;
	double				height;
	t_coord_3d			position;
	t_3d_basis			basis;
	struct s_cylinder	*next;
	t_texture			texture;
	int					caps;
}						t_cylinder;

typedef struct			s_triangle
{
	t_3d_basis			basis;
	t_coord_3d			c;
	t_coord_3d			p1;
	t_coord_3d			p2;
	t_coord_3d			p3;
	void				*parent;
	struct s_triangle	*next;
	t_texture			texture;
}						t_triangle;

typedef struct			s_rectangle
{
	double				width;
	double				height;
	t_3d_basis			basis;
	t_coord_3d			position;
	struct s_rectangle	*next;
	t_texture			texture;
}						t_rectangle;

typedef struct			s_cone
{
	double				angle;
	double				height;
	t_3d_basis			basis;
	t_coord_3d			vertex;
	struct s_cone		*next;
	t_texture			texture;
}						t_cone;

typedef struct			s_cube
{
	double				radius;
	t_3d_basis			basis;
	t_coord_3d			center;
	t_square			*faces[6];
	struct s_cube		*next;
	t_texture			texture;
}						t_cube;

typedef struct			s_pyramid
{
	t_coord_3d			apex;
	t_square			*base;
	t_triangle			*faces[4];
	struct s_pyramid	*next;
	t_texture			texture;
}						t_pyramid;

typedef	struct			s_skybox
{
	t_square			faces[6];
}						t_skybox;

typedef struct			s_sepia
{
	char				on;
	char				set;
}						t_sepia;

typedef struct			s_anti_aliasing
{
	int					factor;
	char				set;
}						t_anti_aliasing;

typedef struct  s_display
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	void				*img_addr;
	int					bpp;
	int					local_endian;
	int					server_endian;
	int					line_size;
}						t_display;


/************ configuration functions ***********/

void					configuration_reader(char *input_file, void **entities);

int						update_start(char *line, int start);
int						find_next_arg(char *line, int start);
int						check_end_entity_info(char *line, int start, int ret);

int						fetch_rgb(char *line, t_rgb *rgb, int start);
int						fetch_point_3d(char *line, t_coord_3d *point, \
						int start);
int						fetch_vector_3d(char *line, t_coord_3d *vector, \
						int start);
void					ft_dclst_add_head(void **lst_tail, void *new, int type);
void					ft_dclst_destroy(void **tail, int type);

void					ft_lst_add_head(void **lst_tail, void *new, int type);
void					ft_lst_destroy(void **lst_tail, int type);

void					destroy_entities(void **entities);

void					*get_next_lst_mem(void *lst_mem, int type);
void					*get_previous_lst_mem(void *lst_mem, int type);


void					ft_update_next(void *lst_mem, void *next, int type);
void					ft_update_previous(void *lst_mem, void *previous, int type);

int						get_entity_info(char *entity_name, void **entities, \
						char *line);

int						get_radius(char *line, double *radius, int start);
int						get_grid_len(char *line, double *grid_len, int start);
int						get_texture(char *line, t_texture *texture, \
						t_display *display, int type);
int						get_texture_color(char *line, t_texture *texture, int start);
int						get_texture_type(char *line, char *texture_type, int start);
int						get_texture_map(char *line, t_map *map, t_display *display, \
						int start);
void					initialise_map_dimension(t_texture *texture);
void					get_triangle_basis(t_triangle *triangle);
void					prepare_triangle_mapping(t_triangle *triangle);
void					get_triangle_texture_center(t_triangle *triangle);

int						get_resolution(char *line, void **entities);
int						get_ambient_light(char *line, void **entities);
int						get_camera(char *line, void **entities);
int						get_light(char *line, void **entities);
int						get_sphere(char *line, void **entities);
int						get_plane(char *line, void **entities);
int						get_square(char *line, void **entities);
int						get_cylinder(char *line, void **entities);
int						get_triangle(char *line, void **entities);
int						get_cone(char *line, void **entities);
int						get_cube(char *line, void **entities);
int						get_pyramid(char *line, void **entities);
int						get_skybox(char *line, void **entities);
int						get_sepia(char *line, void **entities);
int						get_anti_aliasing(char *line, void **entities);

int						build_cube(t_cube *cube, void **entities);
int						construct_cubes(t_cube *tail, void **entities);

void					build_cube_faces(t_square *faces[6], t_coord_3d position, \
						double radius, t_coord_3d *base);

int						build_pyramid(t_pyramid *pyramid, void **entities);
int						construct_pyramids(t_pyramid *tail, void **entities);

void					build_pyramid_faces(t_pyramid *pyramid, double radius, \
						t_coord_3d center);

void					get_screen_pixel(void **entities);

int						check_critical_entities(void **entities);

void					manage_config_error(int fd, char *line, \
						void **entities, int er_nb);
void					manage_exec_error(void **entities, int error_number);
void					display_error_message(int error_number);


/*********** printing entities functions ************/

void					ft_print_object_position(void *object, int type);

void					print_entity(void **entities, int type);

void					print_rgb(t_rgb rgb);
void					print_pixel(t_pixel pixel);
void					print_smat_3d(t_smat_3d m);
void					print_coord_3d(t_coord_3d point);
void					print_3d_basis(t_3d_basis basis);
void					print_texture(t_texture *texture);

void					print_resolution(t_resolution *resolution);
void					print_ambient_light(t_ambient *ambient);
void					print_camera(t_camera *camera);
void					print_light(t_light *light);
void					print_sphere(t_sphere *sphere);
void					print_plane(t_plane *plane);
void					print_square(t_square *square);
void					print_cylinder(t_cylinder *cylinder);
void					print_triangle(t_triangle *triangle);
void					print_cone(t_cone *tail);


#endif
