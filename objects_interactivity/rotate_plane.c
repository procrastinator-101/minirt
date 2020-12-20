/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:46:38 by youness           #+#    #+#             */
/*   Updated: 2020/11/04 11:58:45 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	rotate_plane(t_plane *plane, t_smat_3d m)
{
	plane->basis.u = smat_vec_3d_product(m, plane->basis.u);
	plane->basis.v = smat_vec_3d_product(m, plane->basis.v);
	plane->basis.w = smat_vec_3d_product(m, plane->basis.w);
	normalise_3d_vec(&(plane->basis.u));
	normalise_3d_vec(&(plane->basis.v));
	normalise_3d_vec(&(plane->basis.w));
}
