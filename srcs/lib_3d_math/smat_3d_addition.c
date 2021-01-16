/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smat_3d_addition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 10:23:44 by youness           #+#    #+#             */
/*   Updated: 2020/06/24 10:42:44 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_3d_math.h"

t_smat_3d	smat_3d_addition(t_smat_3d a, t_smat_3d b)
{
	a.v1 = coord_3d_add(a.v1, b.v1);
	a.v2 = coord_3d_add(a.v2, b.v2);
	a.v3 = coord_3d_add(a.v3, b.v3);
	return (a);
}
