/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/24 12:32:37 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_coord_3d	plane_normal(t_plane *plane, t_coord_3d p, t_coord_3d d)
{
	t_coord_3d	n;
	t_3d_basis	basis;

	if (dot_product(plane->basis.w, d) < 0.0)
		n = plane->basis.w;
	else
		n = scalar_product(plane->basis.w, -1);
	if (plane->texture.type[1] == BUMP_MAP)
		n = get_bump_normal(&(plane->texture.bump_map), &(plane->basis), n, \
			coord_3d_minus(p, plane->position));
	else if (plane->texture.type[1] == WAVE)
	{
		basis = plane->basis;
		basis.w = n;
		n = get_wave_normal(basis, plane->position, p, \
			get_wave_length(plane->texture));
	}
	return (n);
}
