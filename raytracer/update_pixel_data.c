/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pixel_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 13:54:58 by youness           #+#    #+#             */
/*   Updated: 2020/12/27 10:34:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static void	copy_pixel_data(t_display *display, unsigned char *image, int x, \
							unsigned char *pixel)
{
	int				bpp;
	unsigned char	src;
	unsigned char	dst;
	unsigned char	temp;
	unsigned char	shift;

	bpp = display->bpp;
	if (display->local_endian)
		src = bpp < 8 ? bpp : 8;
	else
		src = bpp % 8 ? bpp % 8 : 8;
	dst = 8 - (x * bpp) % 8;
	while (bpp > 0)
	{
		shift = abs(dst - src);
		temp = dst > src ? *pixel << shift : *pixel >> shift;
		*image = dst < 8 ? temp + *image : temp;
		bpp -= dst < src ? dst : src;
		temp = dst;
		dst = dst > src ? shift : 8;
		src = src > temp ? shift : 8;
		pixel += src == 8;
		image += dst == 8;
	}
}

void		update_pixel_data(t_display *display, int x, int y, unsigned color)
{
	unsigned char	*pixel;
	unsigned char	*image;

	pixel = (unsigned char *)(&color);
	color = mlx_get_color_value(display->mlx_ptr, color);
	if (!display->local_endian)
		pixel += 3 - display->bpp / 8 + !(display->bpp % 8);
	image = display->img_addr + y * display->line_size + x * display->bpp / 8;
	copy_pixel_data(display, image, x, pixel);
}
