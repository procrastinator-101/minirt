/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:41:11 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/09 22:34:30 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	intersect_square(t_ray ray, t_square *square)
{
	double		a;
	double		b;
	t_coord_3d	v;
	t_coord_3d	x;

	v = coord_3d_minus(ray.direction, ray.origin);
	a = dot_product(square->v, v);
	b = dot_product(square->v, coord_3d_minus(ray.origin, square->position));
	if (a == 0.0)
		return (INFINITY);
	b /= -a;
	if (b < 0.0)
		return (INFINITY);
	x = coord_3d_plus(ray.origin, scalar_product(v, b));
	if (fabs(x.x) <= fabs(square->position.x + square->height / 2.0))
	   if (fabs(x.y) <= fabs(square->position.y + square->height / 2.0))	
		   return (b);
	return (INFINITY);
}
