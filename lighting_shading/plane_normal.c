/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/27 10:19:25 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static	t_coord_3d	tilt_point_coordinates(t_plane *plane, t_coord_3d p)
{
	double		x;
	double		y;
	t_coord_3d	p1;

	p = coord_3d_minus(p, plane->position);
	x = fabs(fmod(dot_product(p, plane->basis.u), PLANE_TILTING_SIZE));
	y = fabs(fmod(dot_product(p, plane->basis.v), PLANE_TILTING_SIZE));
	if (x > PLANE_TILTING_SIZE / 2.0)
		x -= PLANE_TILTING_SIZE;
	if (y > PLANE_TILTING_SIZE / 2.0)
		y -= PLANE_TILTING_SIZE;
	p1 = coord_3d_plus(plane->position, scalar_product(plane->basis.u, x));
	p1 = coord_3d_plus(p1, scalar_product(plane->basis.v, y));
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
			tilt_point_coordinates(plane, p));
	else if (plane->texture.type[1] == WAVE)
	{
		basis = plane->basis;
		basis.w = n;
		n = get_wave_normal(basis, plane->position, p, \
			get_wave_length(plane->texture));
	}
	return (n);
}
