/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_left_corner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:29:35 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 12:54:21 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_coord_3d	get_left_corner(t_camera *camera, t_screen screen)
{
	t_coord_3d	start;
	t_coord_3d	temp;

	start = coord_3d_add(camera->position, screen.w);
	temp = scalar_product(screen.u, -screen.width);
	start = coord_3d_add(start, temp);
	temp = scalar_product(screen.v, screen.height);
	start = coord_3d_add(start, temp);
	temp = scalar_product(camera->pixel.u, 0.5);
	start = coord_3d_add(start, temp);
	temp = scalar_product(camera->pixel.v, 0.5);
	start = coord_3d_sub(start, temp);
	return (start);
}
