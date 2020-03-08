/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/08 15:16:08 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static double	find_intersection(t_ray ray, t_sphere *sphere)
{
	double		a;
	double		b;
	double		c;
	double		x1;
	double		x2;
	double		det;
	t_coord_3d	v;

	v = coord_3d_minus(ray.direction, ray.origin);
	a = dot_product(v, v);
	b = 2 * dot_product(v, coord_3d_minus(ray.origin, sphere->center));
	v = coord_3d_minus(ray.origin, sphere->center);
	c = dot_product(v, v) - pow(sphere->radius, 2);
	det = pow(b, 2) - 4 * a * c;
	if (det < 0)
		return (INFINITY);
	x1 = (-b + sqrt(det)) / (2 * a);
	x2 = (-b - sqrt(det)) / (2 * a);
	if (x1 < x2)
	{
		if (x1 >= 0.0)
			return (x1);
		return (x2 >= 0.0 ? x2 : INFINITY);
	}
	else
	{
		if (x2 >= 0)
			return (x2);
		return (x1 >= 0.0 ? x1 : INFINITY);
	}
}

t_intersection	intersect_sphere(t_ray ray, t_sphere *tail)
{
	double			distance;
	t_sphere		*sphere;
	t_intersection	closest_inter;

	sphere = tail;
	closest_inter.distance = INFINITY;
	closest_inter.object = tail;
	closest_inter.type = SPHERE;
	if (tail)
	{
		distance = find_intersection(ray, tail);
		if (distance < INFINITY && distance >= 0.0)
			closest_inter.distance = distance;
		sphere = sphere->next;
		while (sphere != tail)
		{
			distance = find_intersection(ray, sphere);
			if (distance < closest_inter.distance && distance >= 0.0)
			{
				closest_inter.distance = distance;
				closest_inter.object = sphere;
			}
			sphere = sphere->next;
		}
	}
	return (closest_inter);
}
