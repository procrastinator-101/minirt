/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 21:06:02 by youness           #+#    #+#             */
/*   Updated: 2020/06/21 21:07:54 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	translate_camera(t_camera *camera, t_coord_3d v)
{
	camera->position = coord_3d_plus(camera->position, v);
}
