/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 22:35:13 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/10 20:16:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	intersect_triangle(t_ray ray, t_triangle *triangle)
{
	double		t;
	t_coord_3d	m;
	t_coord_3d	e1;
	t_coord_3d	e2;
	t_coord_3d	v;
	t_coord_3d	p;
	t_coord_3d	q;

	m = coord_3d_minus(ray.origin, triangle->p1);
	e1 = coord_3d_minus(triangle->p2, triangle->p1);
	e2 = coord_3d_minus(triangle->p3, triangle->p1);
	v = coord_3d_minus(ray.direction, ray.origin);
	//normalise_3d_vec(&v);
	p = cross_product(v, e2);
	q = cross_product(m, e1);
	t = 1.0 / dot_product(p, e1);
	t *= dot_product(q, e2);
	if (t >= 0.0)
	{
	print_coord_3d(ray.origin);
	print_coord_3d(ray.direction);
	print_coord_3d(v);
	print_coord_3d(triangle->p1);
	print_coord_3d(triangle->p2);
	print_coord_3d(triangle->p3);
	print_coord_3d(m);
	print_coord_3d(e1);
	print_coord_3d(e2);
	print_coord_3d(p);
	print_coord_3d(q);
	printf("t = %f\n", t);
	exit(1);
	}
	return (t >= 0.0 ? t : INFINITY);
}
