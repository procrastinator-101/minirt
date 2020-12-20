/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/25 14:08:27 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_coord_3d	plane_normal(t_plane *plane, t_coord_3d p, t_coord_3d d)
{
	t_coord_3d	n;

	if (dot_product(plane->basis.w, d) <= 0.0)
		n = plane->basis.w;
	else
		n = scalar_product(plane->basis.w, -1);
	if (plane->texture.type[1] == BUMP_MAP)
		n = get_bump_normal(&(plane->texture.bump_map), &(plane->basis), n, \
			p);
	else if (plane->texture.type[1] == WAVE)
		n = get_wave_normal(plane->basis, plane->position, p, d);
	return (n);
}
