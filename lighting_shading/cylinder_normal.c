/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/21 18:43:41 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static int			is_on_caps(t_cylinder *cylinder, t_coord_3d p, \
					t_coord_3d p1)
{
	t_coord_3d p2;

	if (coord_3d_len(coord_3d_minus(p, p1)) <= cylinder->radius)
		return (1);
	p2 = coord_3d_plus(p1, scalar_product(cylinder->basis.w, \
		cylinder->height));
	if (coord_3d_len(coord_3d_minus(p, p2)) <= cylinder->radius)
		return (1);
	return (0);
}

static t_coord_3d	get_dirupted_normal(t_cylinder *cylinder, t_coord_3d p, \
					t_coord_3d n, int caps)
{
	t_3d_basis	basis;

	if (cylinder->texture.type[1] == BUMP_MAP)
		n = get_bump_normal(&(cylinder->texture.bump_map), \
			&(cylinder->basis), n, p);
	else if (cylinder->texture.type[1] == WAVE)
	{
		basis = cylinder->basis;
		if (!caps)
		{
			basis.v = basis.w;
			basis.u = basis.w;
		}
		n = get_wave_normal(basis, n, cylinder->position, p);
	}
	return (n);
}

t_coord_3d			cylinder_normal(t_cylinder *cylinder, t_coord_3d p, \
					t_coord_3d d)
{
	int			caps;
	double		temp;
	t_coord_3d	n;
	t_coord_3d	v;

	caps = 0;
	if (cylinder->caps && is_on_caps(cylinder, p, cylinder->position))
	{
		n = cylinder->basis.w;
		caps = 1;
	}
	else
	{
		v = coord_3d_minus(p, cylinder->position);
		temp = dot_product(cylinder->basis.w, v);
		n = scalar_product(cylinder->basis.w, temp);
		n = coord_3d_minus(v, n);
		normalise_3d_vec(&n);
	}
	if (dot_product(n, d) >= 0.0)
		n = scalar_product(n, -1);
	return (get_dirupted_normal(cylinder, p, n, caps));
}
