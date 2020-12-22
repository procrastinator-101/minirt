/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_triangle_mapping.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:15:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/22 10:50:30 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void		prepare_triangle_mapping(t_triangle *triangle)
{
	double		len[3];
	t_coord_3d	v1;
	t_coord_3d	v2;
	t_coord_3d	v3;

	v1 = coord_3d_minus(triangle->p2, triangle->p1);
	v2 = coord_3d_minus(triangle->p3, triangle->p1);
	len[0] = coord_3d_len(v1);
	len[1] = coord_3d_len(v2);
	len[2] = coord_3d_len(coord_3d_minus(triangle->p3, triangle->p2));
	triangle->basis.u = v1;
	v3 = cross_product(v2, v1);
	triangle->basis.v = cross_product(v1, v3);
	normalise_3d_vec(&(triangle->basis.u));
	normalise_3d_vec(&(triangle->basis.v));
	triangle->basis.w = cross_product(triangle->basis.u, triangle->basis.v);
	triangle->texture.width = ft_max(len[0], ft_max(len[1], len[2]));
	triangle->texture.height = triangle->texture.width;
	get_triangle_texture_center(triangle);
}
