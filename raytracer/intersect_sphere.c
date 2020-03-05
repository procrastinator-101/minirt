/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/05 20:46:54 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

find_intersection(t_ray ray, t_sphere *sphere)
{
	double	a;
	double	b;
	double	c;

	a = dot_product(ray.direction, ray.direction);
	b = 2 * dot_product(ray.origin, ray.direction);
	c = dot_product(ray.origin, ray.origin);

}

t_intersection	intersect_sphere(t_ray ray, t_camera *tail)
{
	double			distance;
	t_sphere		*sphere;
	t_intersection	temp;
	t_intersection	closest_inter;

	closest_inter.distance = INFINITY;
	sphere = tail;
	if (tail)
	{
		while (tail != sphere->next)
		{
			distance = find_intersection(ray, tail);
		}
	}
	return (closest_inter);
}
