/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/06 10:54:15 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static double	find_intersection(t_ray ray, t_sphere *sphere)
{
	double		a;
	double		b;
	double		c;
	double		det;
	t_coord_3d	v;

	v = coord_3d_minus(ray.direction, ray.origin);
	a = dot_product(v, v);
	b = 2 * dot_product(v, coord_3d_minus(ray.origin, sphere->center));
	c = dot_product(ray.origin, ray.origin) \
		- 2 * dot_product(ray.origin, sphere->center) \
		+ dot_product(sphere->center, sphere->center);
	det = pow(b, 2) - 4 * a * c;
	if (det < 0)
		return (INFINITY);
	if (det == 0)
		return (-b / (2 * a));
	return (ft_min((-b + sqrt(det)) / (2 * a), (-b - sqrt(det)) / (2 * a)));
}

t_intersection	intersect_sphere(t_ray ray, t_camera *tail)
{
	double			distance;
	t_sphere		*sphere;
	t_intersection	temp;
	t_intersection	closest_inter;

	closest_inter.distance = INFINITY;
	closest_inter.object = tail;
	closest_inter.type = SPHERE;
	sphere = tail;
	if (tail)
	{
		closest_inter.distance = find_intersection(ray, tail);
		sphere = sphere->next;
		while (sphere != tail)
		{
			distance = find_intersection(ray, tail);
			if (distance < closest_inter.distance)
			{
				closest_inter.distance = distance;
				closest_inter.object = sphere;
			}
			sphere = sphere->next;
		}
	}
	return (closest_inter);
}
