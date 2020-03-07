/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:04:02 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 16:27:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	fill_screen(t_screen *screen, double width, double height)
{
	double	fov_radian;

	fov_radian = camera->fov / 2.0 * (M_PI / 180.0);
	screen.width = tan(fov_radian);
	screen.height = camera->screen.width * aspect_ratio;
	get_base_3d(&(screen->w), &(screen->v), &(screen->u));
	normalise_3d_vec(&(screen->w));
	normalise_3d_vec(&(screen->v));
	normalise_3d_vec(&(screen->u));
}

void		get_screen(void **entities)
{
	double		width;
	double		height;
	double		aspect_ratio;
	t_camera	*camera;

	width = ((t_resolution *)entities[RESOLUTION])->width;
	height = ((t_resolution *)entities[RESOLUTION])->height;
	aspect_ratio = width / height;
	camera = entities[CAMERA];
	if (camera)
	{
		fill_screen(&(camera->screen), width, height, aspect_ratio);
		camera = camera->next;
		while (camera != entities[CAMERA])
		{
			fill_screen(&(camera->screen), width, height, aspect_ratio);
			camera = camera->next;
		}
	}
}
