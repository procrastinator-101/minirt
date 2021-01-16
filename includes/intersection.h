/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:41:11 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/16 18:48:42 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include <math.h>
# include "lib_3d_math.h"
# include "configuration_reader.h"

typedef struct		s_ray
{
	t_coord_3d		origin;
	t_coord_3d		direction;
}					t_ray;

typedef struct		s_intersection
{
	double			distance;
	void			*object;
	int				type;
}					t_intersection;

double				get_right_solution(double t1, double t2);

t_intersection		get_closest_inter(t_ray ray, void **entities);
t_intersection		intersect_object_class(t_ray ray, void *class_tail, \
					int type);

double				intersect_obstacle_class(t_ray ray, void *class_tail, \
					int type);

double				get_intersection(t_ray ray, void *class, int type);
double				intersect_cylinder(t_ray ray, t_cylinder *cylinder);
double				intersect_plane(t_ray ray, t_plane *plane);
double				intersect_sphere(t_ray ray, t_sphere *sphere);
double				intersect_square(t_ray ray, t_square *square);
double				intersect_triangle(t_ray ray, t_triangle *triangle);
double				intersect_cone(t_ray ray, t_cone *cone);
t_intersection		intersect_skybox(t_ray ray, t_skybox *skybox);

#endif
