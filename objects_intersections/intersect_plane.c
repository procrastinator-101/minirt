/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:18:19 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/04 12:57:41 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

double	intersect_plane(t_ray ray, t_plane *plane)
{
	double		a;
	double		b;

	a = dot_product(plane->basis.w, ray.direction);
	b = dot_product(plane->basis.w, coord_3d_minus(ray.origin, plane->position));
	if (a == 0.0)
		return (b == 0.0 ? 0 : INFINITY);
	b /= -a;
	return (b >= 0.0 ? b : INFINITY);
}
