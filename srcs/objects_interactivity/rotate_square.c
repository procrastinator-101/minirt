/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:48:35 by youness           #+#    #+#             */
/*   Updated: 2020/12/23 09:57:25 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	rotate_square(t_square *square, t_smat_3d m)
{
	square->basis.u = smat_vec_3d_product(m, square->basis.u);
	square->basis.v = smat_vec_3d_product(m, square->basis.v);
	square->basis.w = smat_vec_3d_product(m, square->basis.w);
	normalise_3d_vec(&(square->basis.u));
	normalise_3d_vec(&(square->basis.v));
	normalise_3d_vec(&(square->basis.w));
}
