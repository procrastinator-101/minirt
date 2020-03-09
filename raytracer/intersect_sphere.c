/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/09 17:12:58 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static double	get_right_x(double x1, double x2)
{
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

double			intersect_sphere(t_ray ray, t_sphere *sphere)
{
	double		a;
	double		b;
	double		c;
	double		det;
	t_coord_3d	v;

	v = coord_3d_minus(ray.direction, ray.origin);
	a = dot_product(v, v);
	b = 2 * dot_product(v, coord_3d_minus(ray.origin, sphere->center));
	v = coord_3d_minus(ray.origin, sphere->center);
	c = dot_product(v, v) - pow(sphere->radius, 2);
	det = pow(b, 2) - 4 * a * c;
	if (det < 0 || a == 0.0)
		return (INFINITY);
	return (get_right_x((-b + sqrt(det)) / (2 * a), (-b - sqrt(det)) / (2 * a)));
}
