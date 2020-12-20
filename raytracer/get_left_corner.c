/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_left_corner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:29:35 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/08 17:52:01 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_coord_3d	get_left_corner(t_camera *camera, t_screen screen)
{
	t_coord_3d	start;
	t_coord_3d	temp;

	start = coord_3d_plus(camera->position, screen.w);
	temp = scalar_product(screen.u, -screen.width);
	start = coord_3d_plus(start, temp);
	temp = scalar_product(screen.v, screen.height);
	start = coord_3d_plus(start, temp);
	start.x += camera->pixel.width / 2.0;
	start.y -= camera->pixel.height / 2.0;
	return (start);
}
