/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:55:35 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 15:15:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int	initialise_display(t_display *display, void **entities)
{
	int size_x;
	int size_y;
	int	endian;
	int	size_line;
	int	bits_per_pixel;

	size_x = ((t_resolution *)entities[RESOLUTION])->width;
	size_y = ((t_resolution *)entities[RESOLUTION])->height;
	display->mlx_ptr = mlx_init();
	if (!display->mlx_ptr)
		return (MLX_CONNECTION_ERROR);
	display->win_ptr = mlx_new_window(display->mlx_ptr, size_x, size_y, i\
						"minirt");
	if (!display->win_ptr)
		return (WINDOW_CREATION_ERROR);
	display->img_ptr = mlx_new_image(display->mlx_ptr, size_x, size_y);
	if (!display->img_ptr)
		return (IMAGE_CREATION_ERROR);
	display->img_addr = mlx_get_data_addr(display->img_ptr, bits_per_pixel, \
						size_line, display->endian);
	if (!display->img_addr)
		return (IMAGE_CREATION_ERROR);
}
