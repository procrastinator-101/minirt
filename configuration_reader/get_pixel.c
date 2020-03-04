/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:51:29 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/04 16:52:21 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	get_pixel(void **entities)
{
	double		width;
	double		height;
	t_camera	*tail;

	width = entities[RESOLUTION]->width / 2.0;
	height = entities[RESOLUTION]->height / 2.0;
	tail = entities[CAMERA];
	if (tail)
	{
		while (tail != camera->next)
		{
			camera->pixel.width = camera->screen.width / width;
			camera->pixel.height = camera->screen.height / height;
			camera = camera->next;
		}
	}
}
