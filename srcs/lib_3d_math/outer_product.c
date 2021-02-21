/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outer_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 09:42:04 by youness           #+#    #+#             */
/*   Updated: 2020/06/24 13:44:34 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_3d_math.h"

t_smat_3d	outer_product(t_coord_3d u, t_coord_3d v)
{
	t_smat_3d	m;

	m.v1 = scalar_product(u, v.x);
	m.v2 = scalar_product(u, v.y);
	m.v3 = scalar_product(u, v.z);
	return (m);
}
