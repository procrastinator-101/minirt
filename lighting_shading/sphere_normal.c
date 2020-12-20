/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/26 20:39:43 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_coord_3d	sphere_normal(t_sphere *sphere, t_coord_3d p, t_coord_3d d)
{
	t_coord_3d	n;

	n = coord_3d_minus(p, sphere->center);
	normalise_3d_vec(&n);
	if (sphere->texture.type[1] == BUMP_MAP)
		n = get_bump_normal(&(sphere->texture.bump_map), &(sphere->basis), n, \
			p);
	else if (sphere->texture.type[1] == WAVE)
		n = get_wave_normal(sphere->basis, coord_3d_plus(sphere->center, \
					scalar_product(sphere->basis.w, -sphere->radius)), p, d);
	return (n);
}
