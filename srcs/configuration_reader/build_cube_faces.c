/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cube_faces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:03:11 by youness           #+#    #+#             */
/*   Updated: 2021/01/26 10:53:22 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	build_cube_faces(t_square *faces[6], t_coord_3d position, \
		double radius, t_coord_3d *base)
{
	int	i;
	int	w_index;
	int	v_index;
	int	u_index;

	i = 0;
	while (i < 6)
	{
		w_index = i / 2;
		v_index = w_index + 1 > 2 ? 0 : w_index + 1;
		u_index = v_index + 1 > 2 ? 0 : v_index + 1;
		faces[i]->position = coord_3d_add(position, \
			scalar_product(base[w_index], -radius));
		faces[i + 1]->position = coord_3d_add(position, \
			scalar_product(base[w_index], radius));
		faces[i]->basis.w = base[w_index];
		faces[i]->basis.v = base[v_index];
		faces[i]->basis.u = base[u_index];
		faces[i]->face_number = i;
		faces[i + 1]->basis.w = base[w_index];
		faces[i + 1]->basis.v = base[v_index];
		faces[i + 1]->basis.u = base[u_index];
		faces[i + 1]->face_number = i + 1;
		i += 2;
	}
}
