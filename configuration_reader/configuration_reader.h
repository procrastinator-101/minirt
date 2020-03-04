/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_reader.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:27:58 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/04 18:13:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGURATION_READER_H
# define CONFIGURATION_READER_H

# include "../miniRT.h"

# define ENTITIES_SIZE	10

# define RESOLUTION	1
# define AMBIENT	2
# define CAMERA		3
# define LIGHT		4
# define SPHERE		5
# define PLANE		6
# define SQUARE		7
# define CYLINDER	8
# define TRIANGLE	9

/************** basic data structures **************/

typedef struct			s_point_3d
{
	double				x;
	double				y;
	double				z;
}						t_point_3d;

typedef struct			s_vector_3d
{
	double				x;
	double				y;
	double				z;
}						t_vector_3d;

typedef struct			s_rgb
{
	int					red;
	int					green;
	int					blue;
}						t_rgb;

typedef struct			s_screen
{
	double				width;
	double				height;
}						t_screen;

typedef struct			s_pixel
{
	double				width;
	double				height;
}						t_pixel;

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
	t_point_3d			position;
	t_vector_3d			orientation_vec;
	t_screen			screen;
	t_pixel				pixel;
	struct s_camera     *previous;
	struct s_camera		*next;
	int					fov;
}						t_camera;

typedef struct			s_light
{
	t_point_3d			light_point;
	double				brightness;
	struct s_light		*previous;
	struct s_light		*next;
	t_rgb				rgb;
}						t_light;

typedef struct			s_sphere
{
	t_point_3d			sphere_point;
	double				diameter;
	struct s_sphere		*previous;
	struct s_sphere		*next;
	t_rgb				rgb;
}						t_sphere;

typedef	struct			s_plane
{
	t_point_3d			plane_point;
	t_vector_3d			orientation_vec;
	struct s_plane		*previous;
	struct s_plane		*next;
	t_rgb				rgb;
}						t_plane;

typedef struct			s_square
{
	t_point_3d			square_point;
	t_vector_3d			orientation_vec;
	double				height;
	struct s_square		*previous;
	struct s_square		*next;
	t_rgb				rgb;
}						t_square;

typedef struct			s_cylinder
{
	t_point_3d			cylinder_point;
	t_vector_3d			orientation_vec;
	double				diameter;
	double				height;
	struct s_cylinder	*previous;
	struct s_cylinder	*next;
	t_rgb				rgb;
}						t_cylinder;

typedef struct			s_triangle
{
	t_point_3d			first_point;
	t_point_3d			second_point;
	t_point_3d			third_point;
	struct s_triangle	*previous;
	struct s_triangle	*next;
	t_rgb				rgb;
}						t_triangle;


/************ configuration functions ***********/

int						update_start(char *line, int start);
int						find_next_arg(char *line, int start);

int						fetch_rgb(char *line, t_rgb *rgb, int start);
int						fetch_point_3d(char *line, t_point_3d *point, \
						int start);
int						fetch_vector_3d(char *line, t_vector_3d *vector, \
						int start);

int						ft_atoi_length(char *str, int *len);
double					ft_atod_length(char *str, int *len);

void					ft_lstadd_head(void **lst_tail, void *new, int type);
void					ft_lst_destroy(void **lst_tail, int type);
void					ft_lst_delete(void **lst_tail);

void					*choose_entity_type(void *tail, int type);

int						get_entity_info(char *entity_name, void **entities, \
						char *line);

int						get_resolution(char *line, void **entities);
int						get_ambient_light(char *line, void **entities);
int						get_camera(char *line, void **entities);
int						get_light(char *line, void **entities);
int						get_sphere(char *line, void **entities);
int						get_plane(char *line, void **entities);
int						get_square(char *line, void **entities);
int						get_cylinder(char *line, void **entities);
int						get_triangle(char *line, void **entities);

void					get_screen(void **entities);
void					get_pixel(void **entities);


void					manage_config_error(int fd, char *line, \
						void **entities, int er_nb);
void					display_error_message(int error_number);


/*********** printing entities functions ************/

void    print_entity(void **entities, int type);

void	print_rgb(t_rgb rgb);
void	print_point_3d(t_point_3d point);
void	print_vector_3d(t_vector_3d vector);

void	print_resolution(void **entities);
void	print_ambient_light(void **entities);
void	print_camera(void **entities);
void	print_light(void **entities);
void	print_sphere(void **entities);
void	print_plane(void **entities);
void	print_square(void **entities);
void	print_cylinder(void **entities);
void	print_triangle(void **entities);


#endif
