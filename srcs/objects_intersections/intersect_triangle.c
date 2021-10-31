/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 22:35:13 by yarroubi          #+#    #+#             */
/*   Updated: 2020/06/26 14:22:16 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersection.h"

double	intersect_triangle(t_ray ray, t_triangle *triangle)
{
	double		t;
	double		det;
	double		weights[2];
	t_coord_3d	e[2];
	t_coord_3d	v[3];

	e[0] = coord_3d_sub(triangle->p2, triangle->p1);
	e[1] = coord_3d_sub(triangle->p3, triangle->p1);
	v[0] = cross_product(ray.direction, e[1]);
	det = dot_product(e[0], v[0]);
	if (det > -EPSILON && det < EPSILON)
		return (INFINITY);
	det = 1.0 / det;
	v[1] = coord_3d_sub(ray.origin, triangle->p1);
	weights[0] = dot_product(v[1], v[0]) * det;
	if (weights[0] < 0.0 || weights[0] > 1.0)
		return (INFINITY);
	v[2] = cross_product(v[1], e[0]);
	weights[1] = dot_product(ray.direction, v[2]) * det;
	if (weights[1] < 0.0 || weights[0] + weights[1] > 1)
		return (INFINITY);
	t = dot_product(e[1], v[2]) * det;
	return (t >= 0.0 ? t : INFINITY);
}
