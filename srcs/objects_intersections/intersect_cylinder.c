/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:11:26 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/25 15:00:30 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersection.h"

static double	check_finity(t_ray ray, t_cylinder *cylinder, double x)
{
	double		l;
	t_coord_3d	k;
	t_coord_3d	q;

	if (x < 0)
		return (INFINITY);
	k = coord_3d_add(ray.origin, scalar_product(ray.direction, x));
	q = coord_3d_sub(k, cylinder->position);
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

static double	get_caps(t_ray ray, t_cylinder *cylinder)
{
	double		t[2];
	t_disk		disk;

	disk.position = cylinder->position;
	disk.basis = cylinder->basis;
	disk.radius = cylinder->radius;
	t[0] = intersect_disk(ray, &disk);
	disk.position = scalar_product(cylinder->basis.w, cylinder->height);
	disk.position = coord_3d_add(cylinder->position, disk.position);
	t[1] = intersect_disk(ray, &disk);
	return (get_right_solution(t[0], t[1]));
}

double			intersect_cylinder(t_ray ray, t_cylinder *cylinder)
{
	double		det;
	double		t[2];
	double		e[3];
	t_coord_3d	v[3];

	v[0] = cross_product(ray.direction, cylinder->basis.w);
	v[1] = coord_3d_sub(ray.origin, cylinder->position);
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
		t[1] = get_caps(ray, cylinder);
		return (get_right_solution(t[0], t[1]));
	}
	return (t[0]);
}
