/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 22:35:13 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/13 18:11:13 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	intersect_triangle(t_ray ray, t_triangle *triangle)
{
	double		det;
	double		weights[3];
	t_coord_3d	e[2];
	t_coord_3d	p[2];
	t_coord_3d	d[2];

	d[0] = coord_3d_minus(ray.direction, ray.origin);
	e[0] = coord_3d_minus(triangle->p2, triangle->p1);
	e[1] = coord_3d_minus(triangle->p3, triangle->p1);
	p[0] = cross_product(d[0], e[1]);
	det = dot_product(e[0], p[0]);
	if (det < 0.0)
		return (INFINITY);
	d[1] = coord_3d_minus(ray.origin, triangle->p1);
	weights[1] = dot_product(d[1], p[0]);
	if (weights[1] < 0.0 || weights[1] > det)
		return (INFINITY);
	p[1] = cross_product(d[1], e[0]);
	weights[2] = dot_product(d[0], p[1]);
	if (weights[2] < 0.0 || weights[1] + weights[2] > det)
		return (INFINITY);
	weights[0] = dot_product(e[1], p[1]) / det;
	return (weights[0] >= 0.0 ? weights[0] : INFINITY);
}
