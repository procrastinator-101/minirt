/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_pixels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:52:23 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/06 12:18:22 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	destroy_pixels(void **entities)
{
	int i;
	int	**pixels;

	pixels = (int **)entities[PIXELS];
	i = -1;
	while (pixels[++i])
		free(pixels[i]);
	free(pixels);
}
