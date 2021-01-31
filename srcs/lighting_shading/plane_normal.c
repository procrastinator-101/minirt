/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/31 14:16:02 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static	t_coord_3d	tilt_point(t_plane *plane, t_coord_3d p)
{
	double		x;
	double		y;
	t_coord_3d	p1;

	p = coord_3d_sub(p, plane->position);
	x = dot_product(p, plane->basis.u);
	y = dot_product(p, plane->basis.v);
	x = tilt(x, PLANE_TILTING_SIZE);
	y = tilt(y, PLANE_TILTING_SIZE);
	p1 = scalar_product(plane->basis.u, x);
	p1 = coord_3d_add(p1, scalar_product(plane->basis.v, y));
	return (p1);
}

t_coord_3d			plane_normal(t_plane *plane, t_coord_3d p, t_coord_3d d)
{
	t_coord_3d	n;
	t_3d_basis	basis;

	if (dot_product(plane->basis.w, d) < 0.0)
		n = plane->basis.w;
	else
		n = scalar_product(plane->basis.w, -1);
	if (plane->texture.type[1] == BUMP_MAP)
		n = get_bump_normal(&(plane->texture.bump_map), &(plane->basis), n, \
			tilt_point(plane, p));
	else if (plane->texture.type[1] == WAVE)
	{
		basis = plane->basis;
		basis.w = n;
		n = get_wave_normal(basis, plane->position, p, \
			get_wave_length(plane->texture));
	}
	return (n);
}
