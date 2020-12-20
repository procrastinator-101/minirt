/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smat_vec_3d_product.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 16:01:17 by youness           #+#    #+#             */
/*   Updated: 2020/06/23 07:34:10 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_3d_math.h"

t_coord_3d	smat_vec_3d_product(t_smat_3d m, t_coord_3d w)
{
	t_coord_3d	r;

	r.x = m.v1.x * w.x + m.v2.x * w.y + m.v3.x * w.z;
	r.y = m.v1.y * w.x + m.v2.y * w.y + m.v3.y * w.z;
	r.z = m.v1.z * w.x + m.v2.z * w.y + m.v3.z * w.z;
	return (r);
}
