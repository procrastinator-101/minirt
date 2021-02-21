/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:41:11 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/16 17:51:30 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersection.h"

double	intersect_square(t_ray ray, t_square *square)
{
	double		a;
	double		b;
	double		x;
	double		y;
	t_coord_3d	p;

	a = dot_product(square->basis.w, ray.direction);
	b = dot_product(square->basis.w, coord_3d_sub(ray.origin, \
		square->position));
	if (a == 0.0 && b != 0.0)
		return (INFINITY);
	b = a == 0.0 ? 0 : -b / a;
	if (b < 0.0)
		return (INFINITY);
	p = coord_3d_add(ray.origin, scalar_product(ray.direction, b));
	p = coord_3d_sub(p, square->position);
	x = dot_product(p, square->basis.u);
	y = dot_product(p, square->basis.v);
	if (fabs(x) > square->radius || fabs(y) > square->radius)
		return (INFINITY);
	return (b);
}
