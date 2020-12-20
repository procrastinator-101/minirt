/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotation_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 10:15:06 by youness           #+#    #+#             */
/*   Updated: 2020/06/24 10:43:24 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_smat_3d	get_rotation_matrix(int angle, t_coord_3d n)
{
	double		a;
	double		b;
	t_smat_3d	s;
	t_smat_3d	m;

	a = cos(angle * (M_PI / 180.0));
	b = sin(angle * (M_PI / 180.0));
	m = smat_3d_scalar_product(coord_3d_antimetric_matrix(n), b);
	s = smat_3d_scalar_product(outer_product(n, n), 1 - a);
	m.v1.x += a;
	m.v2.y += a;
	m.v3.z += a;
	return (smat_3d_addition(m, s));
}
