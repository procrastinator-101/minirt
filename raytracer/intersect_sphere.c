/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/04 20:52:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

find_intersection(t_ray ray, t_sphere *sphere)
{
	double	a;
	double	b;
	double	c;

	a = pow(ray.origin.x, 2) + pow(ray.origin.y, 2) + pow(ray.origin.z, 2);
	b = 2 * cross_product(ray.origin, ray.direction);
	c = pow(ray.direction.x, 2) + pow(ray.direction.y, 2) + \
		pow(ray.direction.z, 2);

}

t_intersection	intersect_sphere(t_ray ray, t_camera *tail)
{
	t_sphere		*sphere;
	t_intersection	temp;
	t_intersection	closest_inter;

	closest_inter.distance = DBL_MAX;
	sphere = tail;
	if (tail)
	{
		while (tail != sphere->next)
		{
			t = find_intersection(ray, tail);
		}
	}
}
