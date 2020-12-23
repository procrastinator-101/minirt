/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wave_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:01:48 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/23 09:12:14 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_coord_3d	get_wave_normal(t_3d_basis basis, t_coord_3d c, t_coord_3d p, \
			double wave_length)
{
	double		x;
	double		y;
	double		tmp;
	double		tmp1;
	double		dist;

	x = dot_product(coord_3d_minus(p, c), basis.u);
	y = dot_product(coord_3d_minus(p, c), basis.v);
	dist = sqrt(x * x + y * y);
	get_base_3d(&basis.w, &basis.v, &basis.u);
	tmp = 2 * M_PI * sin((2 * M_PI * dist) / wave_length);
	tmp1 = cos((2 * M_PI * dist) / wave_length);
	tmp = -AMPLITUDE / (dist * dist * dist) * (tmp + tmp1);
	basis.u = coord_3d_plus(basis.u, scalar_product(basis.w, tmp * x));
	basis.v = coord_3d_plus(basis.v, scalar_product(basis.w, tmp * y));
	basis.w = cross_product(basis.u, basis.v);
	normalise_3d_vec(&basis.w);
	return (basis.w);
}
