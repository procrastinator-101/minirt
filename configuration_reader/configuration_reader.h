/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_reader.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:27:58 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/24 21:43:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGURATION_READER_H
# define CONFIGURATION_READER_H

#include "../miniRT.h"

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


/************ entities' data structures ***********/

typedef struct		s_resolution
{
	int				width;
	int				height;
}					t_resolution;

typedef struct		s_ambient
{
	double			ratio;
	int				red;
	int				green;
	int				blue;
}					t_ambient;

typedef struct		s_camera
{
	t_point_3d		position;
	t_vector_3d		orientation_vec;
	double			fov;
	struct s_camera	*next;
}					t_camera;

int 				find_next_arg(char *line, int start);

int					get_resolution(char *line, void **entities);
int					get_ambient_light(char *line, void **entities);
int					get_camera(char *line, void **entities);

#endif
