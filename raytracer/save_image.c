/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:45:37 by youness           #+#    #+#             */
/*   Updated: 2020/10/15 17:40:10 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	save_image(void **entities, char *image_name, char *image)
{
	int				fd;
	t_bitmap		bitmap;

	if (!image_name || !image)
		return ;
	fd = open("output.bmp", O_CREAT | O_WRONLY | O_TRUNC, 777);
	printf("fd = %d\n", fd);
	if (fd <  0)
		manage_exec_error(entities, EFR);//file creating error
	bitmap.bpp = ((t_display *)entities[DISPLAY])->bpp;
	bitmap.line_size = ((t_display *)entities[DISPLAY])->line_size;
	bitmap.width = ((t_resolution *)entities[RESOLUTION])->width;
	bitmap.height = ((t_resolution *)entities[RESOLUTION])->height;
	bitmap.pixel_data = image;
	image_to_bmp(bitmap, fd);
	close(fd);//error check
	terminate_minirt(entities);
}
