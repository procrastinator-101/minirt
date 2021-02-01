/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:52:20 by youness           #+#    #+#             */
/*   Updated: 2021/02/01 12:45:34 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	rotate_around_center(t_triangle *triangle, t_smat_3d m)
{
	int			i;
	t_coord_3d	v[4];

	v[0] = coord_3d_sub(triangle->p1, triangle->centroid);
	v[1] = coord_3d_sub(triangle->p2, triangle->centroid);
	v[2] = coord_3d_sub(triangle->p3, triangle->centroid);
	v[3] = coord_3d_sub(triangle->c, triangle->centroid);
	i = -1;
	while (++i < 4)
		v[i] = smat_vec_3d_product(m, v[i]);
	triangle->p1 = coord_3d_add(triangle->centroid, v[0]);
	triangle->p2 = coord_3d_add(triangle->centroid, v[1]);
	triangle->p3 = coord_3d_add(triangle->centroid, v[2]);
	triangle->c = coord_3d_add(triangle->centroid, v[3]);
	triangle->basis.u = coord_3d_sub(triangle->p2, triangle->p1);
	v[0] = coord_3d_sub(triangle->p3, triangle->p1);
	v[1] = cross_product(v[0], triangle->basis.u);
	triangle->basis.v = cross_product(triangle->basis.u, v[1]);
	triangle->basis.w = cross_product(triangle->basis.u, triangle->basis.v);
}

void		rotate_triangle(t_triangle *triangle, t_smat_3d m)
{
	if (MATHEMATICAL_ROTATION)
	{
		triangle->c = smat_vec_3d_product(m, triangle->c);
		triangle->p1 = smat_vec_3d_product(m, triangle->p1);
		triangle->p2 = smat_vec_3d_product(m, triangle->p2);
		triangle->p3 = smat_vec_3d_product(m, triangle->p3);
		triangle->basis.u = smat_vec_3d_product(m, triangle->basis.u);
		triangle->basis.v = smat_vec_3d_product(m, triangle->basis.v);
		triangle->basis.w = cross_product(triangle->basis.u, triangle->basis.v);
	}
	else
		rotate_around_center(triangle, m);
	normalise_3d_vec(&(triangle->basis.u));
	normalise_3d_vec(&(triangle->basis.v));
	normalise_3d_vec(&(triangle->basis.w));
}
