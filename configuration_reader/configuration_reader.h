/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_reader.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:27:58 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 16:30:17 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGURATION_READER_H
# define CONFIGURATION_READER_H

# include "../miniRT.h"

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

typedef struct			s_point_2d
{
	double				x;
	double				y;
}						t_point_2d;

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
	struct s_camera		*next;
	int					fov;
}						t_camera;

typedef struct			s_light
{
	t_point_3d			light_point;
	double				brightness;
	struct s_light		*next;
	t_rgb				rgb;
}						t_light;

typedef struct			s_sphere
{
	t_point_3d			sphere_point;
	double				diameter;
	struct s_sphere		*next;
	t_rgb				rgb;
}						t_sphere;

typedef	struct			s_plane
{
	t_point_3d			plane_point;
	t_vector_3d			orientation_vec;
	struct s_plane		*next;
	t_rgb				rgb;
}						t_plane;

typedef struct			s_square
{
	t_point_3d			square_point;
	t_vector_3d			orientation_vec;
	double				height;
	struct s_square		*next;
	t_rgb				rgb;
}						t_square;

typedef struct			s_cylindre
{
	t_point_3d			cylindre_point;
	t_vector_3d			orientation_vec;
	double				diameter;
	double				height;
	struct s_cylindre	*next;
	t_rgb				rgb;
}						t_cylindre;

typedef struct			s_triangle
{
	t_point_3d			first_point;
	t_point_3d			second_point;
	t_point_3d			third_point;
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

void					manage_config_error(int fd, char *line, void **entities, \
						int er_nb);
void					display_error_message(int error_number);

#endif
