/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wave_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:01:48 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/26 20:39:48 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_coord_3d	get_wave_normal(t_3d_basis basis, t_coord_3d c, t_coord_3d p, \
			t_coord_3d d)
{
	double x;
	double y;
	double dist;
	t_coord_3d	u;
	t_coord_3d	v;
	t_coord_3d	n;

	x = dot_product(coord_3d_minus(p, c), basis.u);
	y = dot_product(coord_3d_minus(p, c), basis.v);
	dist = sqrt(x * x + y * y);
	u = basis.u;
	n = basis.w;
	
	if (dot_product(n, d) > 0.0)
	{
		u = scalar_product(u, -1);
		n = scalar_product(n, -1);
	}
	if (dist < WAVE_LENGTH * 15)
	{
		double tmp = (-AMPLITUDE * 2) / (dist * dist);
		tmp *= sin(2 * M_PI * dist / WAVE_LENGTH) * (2 * M_PI * dist / WAVE_LENGTH) - cos(2 * M_PI * dist / WAVE_LENGTH);
		u = coord_3d_plus(u, scalar_product(n, tmp * x));
		v = coord_3d_plus(basis.v, scalar_product(n, tmp * y));
		n = cross_product(u, v);
		normalise_3d_vec(&n);
	}


	return (n);
}
