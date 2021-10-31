/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_pyramid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 21:19:33 by youness           #+#    #+#             */
/*   Updated: 2020/11/04 13:42:58 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	translate_pyramid(t_pyramid *pyramid, t_coord_3d v)
{
	int i;

	pyramid->apex = coord_3d_add(pyramid->apex, v);
	i = -1;
	while (++i < 4)
		translate_triangle(pyramid->faces[i], v);
	translate_square(pyramid->base, v);
}
