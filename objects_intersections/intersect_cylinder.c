/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:11:26 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/04 11:51:21 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

static double	check_finity(t_ray ray, t_cylinder *cylinder, double x)
{
	double		l;
	t_coord_3d	k;
	t_coord_3d	q;

	if (x < 0)
		return (INFINITY);
	k = coord_3d_plus(ray.origin, scalar_product(ray.direction, x));
	q = coord_3d_minus(k, cylinder->position);
	l = dot_product(q, cylinder->basis.w);
	if (l < 0.0 || l > cylinder->height + EPSILON)
		return (INFINITY);
	return (x);
}

static double	get_finity(t_ray ray, t_cylinder *cylinder, double a, double b)
{
	if (a < b)
	{
		a = check_finity(ray, cylinder, a);
		if (a != INFINITY)
			return (a);
		return (check_finity(ray, cylinder, b));
	}
	b = check_finity(ray, cylinder, b);
	if (b != INFINITY)
		return (b);
	return (check_finity(ray, cylinder, a));
}

static double	get_caps(t_ray ray, t_cylinder *cylinder, t_coord_3d p1)
{
	double		a;
	double		b;
	double		t[2];
	t_coord_3d	p2;
	t_coord_3d	q[2];

	a = dot_product(ray.direction, cylinder->basis.w);
	b = dot_product(coord_3d_minus(ray.origin, p1), cylinder->basis.w);
	t[0] = a == 0 ? INFINITY : -b / a;
	p2 = coord_3d_plus(p1, scalar_product(cylinder->basis.w, \
		cylinder->height));
	b = dot_product(coord_3d_minus(ray.origin, p2), cylinder->basis.w);
	t[1] = a == 0 ? INFINITY : -b / a;
	q[0] = coord_3d_plus(ray.origin, scalar_product(ray.direction, t[0]));
	q[1] = coord_3d_plus(ray.origin, scalar_product(ray.direction, t[1]));
	if (coord_3d_len(coord_3d_minus(q[0], p1)) > cylinder->radius)
		t[0] = INFINITY;
	if (coord_3d_len(coord_3d_minus(q[1], p2)) > cylinder->radius)
		t[1] = INFINITY;
	return (get_right_solution(t[0], t[1]));
}

double			intersect_cylinder(t_ray ray, t_cylinder *cylinder)
{
	double		det;
	double		t[2];
	double		e[3];
	t_coord_3d	v[3];

	v[0] = cross_product(ray.direction, cylinder->basis.w);
	v[1] = coord_3d_minus(ray.origin, cylinder->position);
	v[2] = cross_product(v[1], cylinder->basis.w);
	e[0] = dot_product(v[0], v[0]);
	e[1] = 2 * dot_product(v[2], v[0]);
	e[2] = dot_product(v[2], v[2]) - cylinder->radius * cylinder->radius;
	det = e[1] * e[1] - 4 * e[0] * e[2];
	if (det < 0.0 || e[0] == 0.0)
		return (INFINITY);
	t[0] = (-e[1] + sqrt(det)) / (2 * e[0]);
	t[1] = (-e[1] - sqrt(det)) / (2 * e[0]);
	t[0] = get_finity(ray, cylinder, t[0], t[1]);
	if (cylinder->caps)
	{
		t[1] = get_caps(ray, cylinder, cylinder->position);
		return (get_right_solution(t[0], t[1]));
	}
	return (t[0]);
}
