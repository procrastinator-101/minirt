/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_reader.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:27:58 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/25 16:07:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGURATION_READER_H
# define CONFIGURATION_READER_H

# include "../miniRT.h"

# define RESOLUTION	0
# define AMBIENT	1
# define CAMERA		2
# define LIGHT		3
# define SPHERE		4
# define PLANE		5
# define SQUARE		6
# define CYLINDER	7
# define TRIANGLE	8

/************** basic data structures **************/

typedef struct		s_point_2d
{
	double			x;
	double			y;
}					t_point_2d;

typedef struct		s_point_3d
{
	double			x;
	double			y;
	double			z;
}					t_point_3d;

typedef struct		s_vector_3d
{
	double			x;
	double			y;
	double			z;
}					t_vector_3d;

typedef struct		s_rgb
{
	int				red;
	int				green;
	int				blue;
}					t_rgb;

/************ entities' data structures ***********/

typedef struct		s_resolution
{
	int				width;
	int				height;
}					t_resolution;

typedef struct		s_ambient
{
	double			ratio;
	t_rgb			rgb;
}					t_ambient;

typedef struct		s_camera
{
	t_point_3d		position;
	t_vector_3d		orientation_vec;
	struct s_camera	*next;
	int				fov;
}					t_camera;

typedef struct		s_light
{
	t_point_3d		light_point;
	double			brightness;
	struct s_light	*next;
	t_rgb			rgb;
}					t_light;

typedef struct		s_sphere
{
	t_point_3d		sphere_point;
	double			diameter;
	struct s_sphere	*next;
	t_rgb			rgb;
}					t_sphere;

typedef	struct		s_plane
{
	t_point_3d		plane_point;
	t_vector_3d		orientation_vec;
	t_rgb			rgb;
}					t_plane;

typedef struct		s_square
{
	t_point_3d		square_point;
	t_vector_3d		orientation_vec;
	double			height;
	t_rgb			rgb;
}					t_square;

typedef struct		s_cylindre
{
	t_point_3d		cylindre_point;
	t_vector_3d		orientation_vec;
	double			diameter;
	double			height;
	t_rgb			rgb;
}					t_cylindre;

typedef struct		s_triangle
{
	t_point_3d		first_point;
	t_point_3d		second_point;
	t_point_3d		third_point;
	t_rgb			rgb;
}					t_triangle;


/************ configuration functions ***********/

int 				find_next_arg(char *line, int start);

int					ft_atoi_length(char *str, int *len);
double				ft_atod_length(char *str, int *len);

void				ft_lstadd_head(void **lst_tail, void *new, int type);

int					get_resolution(char *line, void **entities);
int					get_ambient_light(char *line, void **entities);
int					get_camera(char *line, void **entities);

#endif
