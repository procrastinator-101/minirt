/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_3d_antimetric_matrix.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 10:03:01 by youness           #+#    #+#             */
/*   Updated: 2020/06/24 13:31:02 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_3d_math.h"

t_smat_3d	coord_3d_antimetric_matrix(t_coord_3d v)
{
	t_smat_3d	m;

	m.v1 = get_coord_3d(0, v.z, -v.y);
	m.v2 = get_coord_3d(-v.z, 0, v.x);
	m.v3 = get_coord_3d(v.y, -v.x, 0);
	return (m);
}
