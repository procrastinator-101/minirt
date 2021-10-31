/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_disk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:35:49 by yarroubi          #+#    #+#             */
/*   Updated: 2021/02/24 16:14:41 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersection.h"

double	intersect_disk(t_ray ray, t_disk *disk)
{
	double		a;
	double		b;
	t_coord_3d	p;

	a = dot_product(disk->basis.w, ray.direction);
	b = dot_product(disk->basis.w, coord_3d_sub(ray.origin, disk->center));
	if (a == 0.0 && b != 0.0)
		return (INFINITY);
	b = a == 0.0 ? 0 : -b / a;
	p = coord_3d_add(ray.origin, scalar_product(ray.direction, b));
	p = coord_3d_sub(p, disk->center);
	a = dot_product(p, p);
	if (a > disk->radius * disk->radius)
		return (INFINITY);
	return (b);
}
