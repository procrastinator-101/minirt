/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle_normal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:36:27 by yarroubi          #+#    #+#             */
/*   Updated: 2021/02/24 16:48:30 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_coord_3d	handle_wave_texture(t_rectangle *rectangle, t_coord_3d n, \
					t_coord_3d p)
{
	double		wave_length;
	t_3d_basis	basis;

	wave_length = get_wave_length(rectangle->texture);
	basis = rectangle->basis;
	basis.w = n;
	if (!rectangle->parent)
		n = get_wave_normal(basis, rectangle->position, p, wave_length);
	else if (rectangle->parent_type == PYRAMID)
		n = get_wave_normal(basis, ((t_pyramid *)rectangle->parent)->apex, \
			p, wave_length);
	else if (rectangle->parent_type == HYPERRECTANGLE)
	{
		if (rectangle->face_number > 3)
			basis.u = rectangle->basis.v;
		else if (rectangle->face_number > 1)
			basis.v = rectangle->basis.u;
		n = get_wave_normal(basis, \
			((t_hyperrectangle *)rectangle->parent)->faces[0]->position, \
				p, wave_length);
	}
	return (n);
}

t_coord_3d			rectangle_normal(t_rectangle *rectangle, t_coord_3d p, \
					t_coord_3d d)
{
	t_coord_3d	n;

	if (dot_product(rectangle->basis.w, d) < 0.0)
		n = rectangle->basis.w;
	else
		n = scalar_product(rectangle->basis.w, -1);
	if (rectangle->texture.type[1] == BUMP_MAP)
		n = get_bump_normal(&(rectangle->texture.bump_map), \
			&(rectangle->basis), n, coord_3d_sub(p, rectangle->position));
	else if (rectangle->texture.type[1] == WAVE)
		n = handle_wave_texture(rectangle, n, p);
	return (n);
}
