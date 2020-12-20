/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:55:35 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/20 13:08:55 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	initialise_display(t_display *display, void **entities)
{
	int size_x;
	int size_y;

	size_x = ((t_resolution *)entities[RESOLUTION])->width;
	size_y = ((t_resolution *)entities[RESOLUTION])->height;
	display->win_ptr = mlx_new_window(display->mlx_ptr, size_x, size_y, \
						"minirt");
	if (!display->win_ptr)
		return (EWC);
	display->img_ptr = mlx_new_image(display->mlx_ptr, size_x, size_y);
	if (!display->img_ptr)
		return (EIC);
	display->img_addr = mlx_get_data_addr(display->img_ptr, &(display->bpp), \
		&(display->line_size), &(display->server_endian));
	if (!display->img_addr)
		return (EIC);
	display->local_endian = ft_local_endian();
	return (0);
}
