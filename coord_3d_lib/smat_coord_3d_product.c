/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smat_coord_3d_product.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 16:01:17 by youness           #+#    #+#             */
/*   Updated: 2020/04/25 16:08:34 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coord_3d_lib.h"

t_coord_3d	smat_coord_3d_product(t_smat_3d m, t_coord_3d w)
{
	t_coord_3d	r;

	r.x = dot_product(m.v1, w);
	r.y = dot_product(m.v2, w);
	r.z = dot_product(n.v3, w);
	return (r);
}
