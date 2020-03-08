/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_left_corner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:29:35 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 17:52:48 by yarroubi         ###   ########.fr       */
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
	return (coord_3d_plus(start, temp));
}
