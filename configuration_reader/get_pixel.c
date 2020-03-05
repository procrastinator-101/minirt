/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:51:29 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/05 18:14:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	get_pixel(void **entities)
{
	double		width;
	double		height;
	t_camera	*tail;
	t_camera	*camera;

	width = ((t_resolution *)entities[RESOLUTION])->width / 2.0;
	height = ((t_resolution *)entities[RESOLUTION])->height / 2.0;
	tail = entities[CAMERA];
	camera = tail;
	if (tail)
	{
		camera->pixel.width = camera->screen.width / width;
		camera->pixel.height = camera->screen.height / height;
		camera = camera->next;
		while (tail != camera->next)
		{
			camera->pixel.width = camera->screen.width / width;
			camera->pixel.height = camera->screen.height / height;
			camera = camera->next;
		}
	}
}
