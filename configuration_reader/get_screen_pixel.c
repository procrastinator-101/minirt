/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:23:21 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/09 20:36:37 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	get_screen(t_camera *camera, t_screen *screen, double aspect_ratio)
{
	double		fov_radian;

	fov_radian = camera->fov / 2.0 * (M_PI / 180.0);
	screen->width = tan(fov_radian);
	screen->height = screen->width * aspect_ratio;
	get_base_3d(&(screen->w), &(screen->v), &(screen->u));
	//normalise_3d_vec(&(screen->w));
	normalise_3d_vec(&(screen->v));
	normalise_3d_vec(&(screen->u));
}

static void	get_pixel(t_camera *camera, double width, double height)
{
	camera->pixel.width = camera->screen.width / width * 2.0;
	camera->pixel.height = camera->screen.height / height * 2.0;
}

void		get_screen_pixel(void **entities)
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
		get_screen(camera, &(camera->screen), aspect_ratio);
		get_pixel(camera, width, height);
		camera = camera->next;
		while (camera != entities[CAMERA])
		{
			get_screen(camera, &(camera->screen), aspect_ratio);
			get_pixel(camera, width, height);
			camera = camera->next;
		}
	}
}
