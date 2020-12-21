/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/21 19:20:49 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_coord_3d	square_normal(t_square *square, t_coord_3d p, t_coord_3d d)
{
	t_coord_3d	n;

	if (dot_product(square->basis.w, d) <= 0.0)
		n = square->basis.w;
	else
		n = scalar_product(square->basis.w, -1);
	if (square->texture.type[1] == BUMP_MAP)
		n = get_bump_normal(&(square->texture.bump_map), &(square->basis), n, \
			p);
	else if (square->texture.type[1] == WAVE)
	{
		if (!square->parent)
			n = get_wave_normal(square->basis, n, square->position, p);
		else if (square->parent_type == PYRAMID)
			n = get_wave_normal(square->basis, n, \
				((t_pyramid *)square->parent)->apex, p);
		else if (square->parent_type == CUBE)
			n = get_wave_normal(((t_cube *)square->parent)->faces[0]->basis, n, \
				((t_cube *)square->parent)->faces[0]->position, p);
	}
	return (n);
}
