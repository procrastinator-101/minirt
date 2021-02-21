/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pyramid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:57:40 by youness           #+#    #+#             */
/*   Updated: 2020/11/05 19:38:57 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	rotate_pyramid(t_pyramid *pyramid, t_smat_3d m)
{
	t_coord_3d	v;

	v = coord_3d_sub(pyramid->apex, pyramid->base->position);
	rotate_square(pyramid->base, m);
	v = smat_vec_3d_product(m, v);
	pyramid->apex = coord_3d_add(pyramid->base->position, v);
	build_pyramid_faces(pyramid, pyramid->base->radius, \
		pyramid->base->position);
}
