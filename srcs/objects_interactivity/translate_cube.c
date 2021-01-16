/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_cube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 21:16:33 by youness           #+#    #+#             */
/*   Updated: 2020/11/04 13:43:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	translate_cube(t_cube *cube, t_coord_3d v)
{
	int i;

	cube->center = coord_3d_add(cube->center, v);
	i = -1;
	while (++i < 6)
		translate_square(cube->faces[i], v);
}
