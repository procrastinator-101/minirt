/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:51:13 by youness           #+#    #+#             */
/*   Updated: 2020/11/04 11:56:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	rotate_cylinder(t_cylinder *cylinder, t_smat_3d m)
{
	cylinder->basis.u = smat_vec_3d_product(m, cylinder->basis.u);
	cylinder->basis.v = smat_vec_3d_product(m, cylinder->basis.v);
	cylinder->basis.w = smat_vec_3d_product(m, cylinder->basis.w);
	normalise_3d_vec(&(cylinder->basis.u));
	normalise_3d_vec(&(cylinder->basis.v));
	normalise_3d_vec(&(cylinder->basis.w));
}
