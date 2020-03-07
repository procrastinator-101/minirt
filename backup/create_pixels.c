/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:35:55 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/06 12:19:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	create_pixels(void **entities)
{
	int				i;
	int				width;
	int				height;
	int				**pixels;

	width = ((t_resolution *)entities[RESOLUTION])->width;
	height = ((t_resolution *)entities[RESOLUTION])->height;
	if (!(pixels = malloc((height + 1) * sizeof(int *))))
	{
		destroy_entities(entities);
		display_error_message(MEMORY_ALLOCATION_FAILURE);
	}
	pixels[height] = 0;
	i = -1;
	while (++i < height)
	{
		if (!(pixels[i] = malloc(width * sizeof(height))))
		{
			while (++i < height)
				pixels[i] = 0;
			destroy_entities(entities);
			display_error_message(MEMORY_ALLOCATION_FAILURE);
		}
	}
	entities[PIXELS] = (void *)pixels;
}
