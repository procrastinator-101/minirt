/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pyramid_faces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:35:47 by youness           #+#    #+#             */
/*   Updated: 2020/11/07 17:05:45 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	build_pyramid_faces(t_pyramid *pyramid, double radius, \
		t_coord_3d center)
{
	int			i;
	t_coord_3d	p1;
	t_coord_3d	p2;
	t_coord_3d	u[2];
	t_coord_3d	v[2];

	u[0] = scalar_product(pyramid->base->basis.u, radius);
	u[1] = scalar_product(pyramid->base->basis.u, -radius);
	v[0] = scalar_product(pyramid->base->basis.v, radius);
	v[1] = scalar_product(pyramid->base->basis.v, -radius);
	i = -1;
	while (++i < 4)
	{
		p1 = coord_3d_add(u[i < 2], v[i % 2]);
		p2 = coord_3d_add(u[!(i % 2)], v[i < 2]);
		pyramid->faces[i]->p1 = coord_3d_add(center, p1);
		pyramid->faces[i]->p2 = coord_3d_add(center, p2);
		pyramid->faces[i]->p3 = pyramid->apex;
		get_triangle_basis(pyramid->faces[i]);
		get_triangle_texture_center(pyramid->faces[i]);
	}
}
