/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:18:19 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/09 21:19:53 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	intersect_plane(t_ray ray, t_plane *plane)
{
	double		a;
	double		b;
	t_coord_3d	v;

	v = coord_3d_minus(ray.direction, ray.origin);
	a = dot_product(plane->v, v);
	b = dot_product(plane->v, coord_3d_minus(ray.origin, plane->position));
	if (a == 0.0)
		return (INFINITY);
	b /= -a;
	return (b >= 0.0 ? b : INFINITY);
}
