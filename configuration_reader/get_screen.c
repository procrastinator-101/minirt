/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:04:02 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/05 18:15:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void		get_screen(void **entities)
{
	double		width;
	double		height;
	double		fov_radian;
	double		aspect_ratio;
	t_camera	*camera;

	width = ((t_resolution *)entities[RESOLUTION])->width;
	height = ((t_resolution *)entities[RESOLUTION])->height;
	aspect_ratio = width / height;
	camera = entities[CAMERA];
	if (camera)
	{
		fov_radian = camera->fov / 2.0 * (M_PI / 180.0);
		camera->screen.width = tan(fov_radian);
		camera->screen.height = camera->screen.width * aspect_ratio;
		camera = camera->next;
		while (camera != entities[CAMERA])
		{
			fov_radian = camera->fov / 2.0 * (M_PI / 180.0);
			camera->screen.width = tan(fov_radian);
			camera->screen.height = camera->screen.width * aspect_ratio;
			camera = camera->next;
		}
	}
}
