/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/23 09:28:21 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_coord_3d	triangle_normal(t_triangle *triangle, t_coord_3d p, t_coord_3d d)
{
	t_coord_3d	n;
	t_coord_3d	c;
	t_3d_basis	basis;

	basis = triangle->basis;
	n = triangle->basis.w;
	if (dot_product(n, d) >= 0.0)
		n = scalar_product(n, -1);
	if (triangle->texture.type[1] == BUMP_MAP)
		n = get_bump_normal(&(triangle->texture.bump_map), &basis, n, p);
	else if (triangle->texture.type[1] == WAVE)
	{
		if (triangle->parent)
		{
			c = ((t_pyramid *)triangle->parent)->apex;
			basis = ((t_pyramid *)triangle->parent)->base->basis;
		}
		else
			c = coord_3d_plus(triangle->p1, scalar_product(\
				coord_3d_minus(triangle->p2, triangle->p1), 0.5));
		basis.w = n;
		n = get_wave_normal(basis, c, p, get_wave_length(triangle->texture));
	}
	return (n);
}
