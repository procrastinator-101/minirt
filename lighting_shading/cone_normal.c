/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 10:40:26 by youness           #+#    #+#             */
/*   Updated: 2020/12/24 11:31:41 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_coord_3d	cone_normal(t_cone *cone, t_coord_3d p, t_coord_3d d)
{
	double		temp;
	t_coord_3d	n;
	t_coord_3d	v;
	t_3d_basis	basis;

	v = coord_3d_minus(p, cone->vertex);
	temp = dot_product(cone->basis.w, v);
	n = scalar_product(cone->basis.w, temp);
	n = coord_3d_minus(v, n);
	normalise_3d_vec(&n);
	if (dot_product(n, d) >= 0.0)
		n = scalar_product(n, -1);
	if (cone->texture.type[1] == BUMP_MAP)
		n = get_bump_normal(&(cone->texture.bump_map), &(cone->basis), n, \
			coord_3d_minus(p, cone->vertex));
	else if (cone->texture.type[1] == WAVE)
	{
		basis.u = cone->basis.w;
		basis.v = cone->basis.w;
		basis.w = n;
		n = get_wave_normal(basis, cone->vertex, p, \
			get_wave_length(cone->texture));
	}
	return (n);
}
