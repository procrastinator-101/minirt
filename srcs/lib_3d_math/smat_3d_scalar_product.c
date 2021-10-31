/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smat_3d_scalar_product.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 16:27:07 by youness           #+#    #+#             */
/*   Updated: 2021/01/16 17:11:18 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_3d_math.h"

t_smat_3d	smat_3d_scalar_product(t_smat_3d m, double a)
{
	t_smat_3d	r;

	r.v1 = scalar_product(m.v1, a);
	r.v2 = scalar_product(m.v2, a);
	r.v3 = scalar_product(m.v3, a);
	return (r);
}
