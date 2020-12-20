/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:54:53 by youness           #+#    #+#             */
/*   Updated: 2020/11/04 12:04:04 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	rotate_cone(t_cone *cone, t_smat_3d m)
{
	cone->basis.w = smat_vec_3d_product(m, cone->basis.w);
	cone->basis.v = smat_vec_3d_product(m, cone->basis.v);
	cone->basis.u = smat_vec_3d_product(m, cone->basis.u);
	normalise_3d_vec(&(cone->basis.w));
	normalise_3d_vec(&(cone->basis.v));
	normalise_3d_vec(&(cone->basis.u));
}
