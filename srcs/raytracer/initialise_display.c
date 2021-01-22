/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:55:35 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/22 18:50:12 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	initialise_display(t_display *display, void **entities)
{
	int size_x;
	int size_y;

	size_x = ((t_resolution *)entities[RESOLUTION])->width;
	size_y = ((t_resolution *)entities[RESOLUTION])->height;
	display->win_ptr = mlx_new_window(display->mlx_ptr, size_x, size_y, \
						"minirt");
	if (!display->win_ptr)
		manage_exec_error(entities, EWCF);
	display->img_ptr = mlx_new_image(display->mlx_ptr, size_x, size_y);
	if (!display->img_ptr)
		manage_exec_error(entities, EICF);
	display->img_addr = mlx_get_data_addr(display->img_ptr, &(display->bpp), \
		&(display->line_size), &(display->server_endian));
	if (!display->img_addr)
		manage_exec_error(entities, EIEF);
	display->local_endian = ft_local_endian();
}
