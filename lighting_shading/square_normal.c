/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/23 09:49:58 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static t_coord_3d	handle_wave_texture(t_square *square, t_coord_3d n, \
					t_coord_3d p)
{
	double		wave_length;
	t_3d_basis	basis;

	wave_length = get_wave_length(square->texture);
	basis = square->basis;
	basis.w = n;
	if (!square->parent)
		n = get_wave_normal(basis, square->position, p, wave_length);
	else if (square->parent_type == PYRAMID)
		n = get_wave_normal(basis, ((t_pyramid *)square->parent)->apex, \
			p, wave_length);
	else if (square->parent_type == CUBE)
	{
		if (square->face_number > 3)
			basis.u = square->basis.v;
		else if (square->face_number > 1)
			basis.v = square->basis.u;
		n = get_wave_normal(basis, \
			((t_cube *)square->parent)->faces[0]->position, p, wave_length);
	}
	return (n);
}

t_coord_3d			square_normal(t_square *square, t_coord_3d p, t_coord_3d d)
{
	t_coord_3d	n;

	if (dot_product(square->basis.w, d) < 0.0)
		n = square->basis.w;
	else
		n = scalar_product(square->basis.w, -1);
	if (square->texture.type[1] == BUMP_MAP)
		n = get_bump_normal(&(square->texture.bump_map), &(square->basis), n, \
				p);
	else if (square->texture.type[1] == WAVE)
		n = handle_wave_texture(square, n, p);
	return (n);
}
