/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:49:53 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 17:20:58 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "../minirt.h"

typedef struct	s_ray
{
	t_point_3d	origin;
	t_point_3d	direction;
}				t_ray;

typedef struct	s_intersection
{
	double		distance;
	void		*object;
	int			type;
}				t_intersection;


int				raytracer(t_camera *camera, void **entities);

void			create_pixels(void **entities);
void			destroy_pixels(void **entities);

int				get_color(t_ray ray, void **entities);

t_intersection	get_closest_inter(t_ray ray, void **entity_name);
t_intersection	intersect(t_ray ray, void *class, int type);

t_intersection	intersect_sphere(t_ray ray, t_camera *tail);

#endif
