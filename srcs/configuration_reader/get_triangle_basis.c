/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle_basis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:34:52 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/22 13:06:26 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	get_triangle_basis(t_triangle *triangle)
{
	t_coord_3d	v;

	triangle->basis.u = coord_3d_sub(triangle->p2, triangle->p1);
	triangle->basis.v = coord_3d_sub(triangle->p3, triangle->p1);
	v = cross_product(triangle->basis.v, triangle->basis.u);
	v = cross_product(triangle->basis.u, v);
	normalise_3d_vec(&v);
	normalise_3d_vec(&(triangle->basis.u));
	triangle->basis.v = v;
	triangle->basis.w = cross_product(triangle->basis.u, triangle->basis.v);
}
