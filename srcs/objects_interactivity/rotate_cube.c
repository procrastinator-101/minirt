/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:56:27 by youness           #+#    #+#             */
/*   Updated: 2021/01/26 10:53:47 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	rotate_cube(t_cube *cube, t_smat_3d m)
{
	t_coord_3d	base[3];

	cube->basis.w = smat_vec_3d_product(m, cube->basis.w);
	cube->basis.v = smat_vec_3d_product(m, cube->basis.v);
	cube->basis.u = smat_vec_3d_product(m, cube->basis.u);
	normalise_3d_vec(&(cube->basis.w));
	normalise_3d_vec(&(cube->basis.v));
	normalise_3d_vec(&(cube->basis.u));
	base[0] = cube->basis.w;
	base[1] = cube->basis.v;
	base[2] = cube->basis.u;
	build_cube_faces(cube->faces, cube->center, cube->radius, base);
}
