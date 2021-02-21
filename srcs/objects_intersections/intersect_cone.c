/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 16:29:58 by youness           #+#    #+#             */
/*   Updated: 2020/11/04 11:49:27 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersection.h"

static void	check_ref_cone(double *t, t_cone *cone, t_coord_3d p, t_coord_3d d)
{
	double		a;
	double		b;
	t_coord_3d	q1;
	t_coord_3d	q2;

	q1 = coord_3d_add(p, scalar_product(d, t[0]));
	a = dot_product(cone->basis.w, coord_3d_sub(q1, cone->vertex));
	q2 = coord_3d_add(p, scalar_product(d, t[1]));
	b = dot_product(cone->basis.w, coord_3d_sub(q2, cone->vertex));
	if (a > cone->height || a < 0.0)
		t[0] = -1;
	if (b > cone->height || b < 0.0)
		t[1] = -1;
}

static void	get_solutions(double *t, double *c, double det)
{
	if (c[0] != 0)
	{
		if (det > 0)
		{
			t[0] = (-c[1] + sqrt(det)) / c[0];
			t[1] = (-c[1] - sqrt(det)) / c[0];
		}
		else if (det == 0)
			t[0] = -c[1] / c[0];
	}
	else
	{
		if (c[1] != 0)
			t[0] = -c[2] / (2 * c[1]);
		else if (c[2] == 0)
			t[0] = 0;
	}
}

double		intersect_cone(t_ray ray, t_cone *cone)
{
	double		det;
	double		t[2];
	double		temp[3];
	double		param[3];
	t_coord_3d	v;

	v = coord_3d_sub(ray.origin, cone->vertex);
	temp[0] = cos(cone->angle);
	temp[1] = dot_product(ray.direction, cone->basis.w);
	temp[2] = dot_product(v, cone->basis.w);
	temp[0] *= temp[0];
	param[0] = temp[1] * temp[1];
	param[0] -= dot_product(ray.direction, ray.direction) * temp[0];
	param[1] = temp[1] * temp[2] - dot_product(v, ray.direction) * temp[0];
	param[2] = temp[2] * temp[2] - dot_product(v, v) * temp[0];
	det = param[1] * param[1] - param[0] * param[2];
	if (det < 0)
		return (INFINITY);
	t[0] = -1;
	t[1] = -1;
	get_solutions(t, param, det);
	check_ref_cone(t, cone, ray.origin, ray.direction);
	return (get_right_solution(t[0], t[1]));
}
