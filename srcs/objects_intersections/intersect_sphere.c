/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/04/25 20:26:13 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersection.h"

double			intersect_sphere(t_ray ray, t_sphere *sphere)
{
	double		t[2];
	double		e[3];
	double		det;
	t_coord_3d	v;

	e[0] = dot_product(ray.direction, ray.direction);
	v = coord_3d_sub(ray.origin, sphere->center);
	e[1] = 2 * dot_product(ray.direction, v);
	e[2] = dot_product(v, v) - sphere->radius * sphere->radius;
	det = e[1] * e[1] - 4 * e[0] * e[2];
	if (det < 0 || e[0] == 0.0)
		return (INFINITY);
	t[0] = (-e[1] + sqrt(det)) / (2 * e[0]);
	t[1] = (-e[1] - sqrt(det)) / (2 * e[0]);
	return (get_right_solution(t[0], t[1]));
}
