/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/21 19:20:19 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_coord_3d	triangle_normal(t_triangle *triangle, t_coord_3d p, t_coord_3d d)
{
	t_coord_3d	v;
	t_coord_3d	u;
	t_coord_3d	n;

	v = coord_3d_minus(triangle->p2, triangle->p1);
	u = coord_3d_minus(triangle->p3, triangle->p1);
	n = cross_product(u, v);
	normalise_3d_vec(&n);
	if (dot_product(n, d) > 0.0)
		n = scalar_product(n, -1);
	if (triangle->texture.type[1] == BUMP_MAP)
		n = get_bump_normal(&(triangle->texture.bump_map), \
			&(triangle->basis), n, p);
	else if (triangle->texture.type[1] == WAVE)
	{
		if (!triangle->parent)
			n = get_wave_normal(triangle->basis, n, coord_3d_plus(triangle->p1, \
				scalar_product(v, 0.5)), p);
		else
			n = get_wave_normal(((t_pyramid *)triangle->parent)->base->basis, \
				n, ((t_pyramid *)triangle->parent)->apex, p);
	}
	return (n);
}
