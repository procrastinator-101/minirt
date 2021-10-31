/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/24 11:28:54 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_coord_3d	sphere_normal(t_sphere *sphere, t_coord_3d p, t_coord_3d d)
{
	t_coord_3d	n;
	t_3d_basis	basis;

	n = coord_3d_sub(p, sphere->center);
	normalise_3d_vec(&n);
	if (dot_product(n, d) >= 0.0)
		n = scalar_product(n, -1);
	if (sphere->texture.type[1] == BUMP_MAP)
		n = get_bump_normal(&(sphere->texture.bump_map), &(sphere->basis), n, \
			coord_3d_sub(p, sphere->center));
	else if (sphere->texture.type[1] == WAVE)
	{
		basis = sphere->basis;
		basis.w = n;
		n = get_wave_normal(basis, coord_3d_add(sphere->center, \
			scalar_product(sphere->basis.w, -sphere->radius)), p, \
				get_wave_length(sphere->texture));
	}
	return (n);
}
