/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle_texture_center.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:44:58 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/14 11:57:48 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	get_triangle_texture_center(t_triangle *triangle)
{
	double		len_v1;
	t_coord_3d	v;
	t_coord_3d	v1;
	t_coord_3d	v2;

	v1 = coord_3d_minus(triangle->p2, triangle->p1);
	v2 = coord_3d_minus(triangle->p3, triangle->p1);
	len_v1 = coord_3d_len(v1);
	triangle->centroid = coord_3d_plus(triangle->p1, scalar_product(v1, 0.5));
	v = scalar_product(triangle->basis.u, triangle->texture.width / 2.0);
	if (triangle->texture.width == len_v1 || dot_product(v1, v2) >= 0)
		triangle->c = coord_3d_plus(triangle->p1, v);
	else
		triangle->c = coord_3d_minus(triangle->p2, v);
	triangle->c = coord_3d_plus(triangle->c, \
		scalar_product(triangle->basis.v, triangle->texture.height / 2.0));
}
