/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:45:37 by youness           #+#    #+#             */
/*   Updated: 2021/01/02 10:49:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	save_image(void **entities, char *image)
{
	int				fd;
	t_bitmap		bitmap;

	if (!image)
		return ;
	fd = open("output.bmp", O_RDWR | O_CREAT, 777);
	printf("fd = %d\n", fd);
	if (fd < 0)
		manage_exec_error(entities, EBFOF);
	bitmap.bpp = ((t_display *)entities[DISPLAY])->bpp;
	bitmap.line_size = ((t_display *)entities[DISPLAY])->line_size;
	bitmap.width = ((t_resolution *)entities[RESOLUTION])->width;
	bitmap.height = ((t_resolution *)entities[RESOLUTION])->height;
	bitmap.pixel_data = image;
	image_to_bmp(bitmap, fd);
	if (close(fd) == -1)
		manage_exec_error(entities, EBFCF);
	terminate_minirt(entities);
}
