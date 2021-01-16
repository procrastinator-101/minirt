/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_bmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 14:09:38 by youness           #+#    #+#             */
/*   Updated: 2021/01/02 10:52:31 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	create_bmp_file_header(char *header, int img_size)
{
	header[0] = 'B';
	header[1] = 'M';
	convert_to_lit_end(header + 2, 54 + img_size, 4);
	ft_bzero(header + 6, 4);
	convert_to_lit_end(header + 10, 54, 4);
}

static void	create_bmp_info_header(char *header, t_bitmap bitmap)
{
	convert_to_lit_end(header, 40, 4);
	convert_to_lit_end(header + 4, bitmap.width, 4);
	convert_to_lit_end(header + 8, bitmap.height, 4);
	convert_to_lit_end(header + 12, 1, 2);
	convert_to_lit_end(header + 14, bitmap.bpp, 2);
	ft_bzero(header + 16, 4);
	convert_to_lit_end(header + 20, 0, 4);
	convert_to_lit_end(header + 24, 17400, 4);
	convert_to_lit_end(header + 28, 17400, 4);
	ft_bzero(header + 32, 8);
}

int			image_to_bmp(t_bitmap bitmap, int fd)
{
	int		nb_pads;
	int		row_size;
	char	file_header[14];
	char	info_header[40];

	row_size = (bitmap.width * bitmap.bpp) / 8;
	row_size += (bitmap.width * bitmap.bpp) % 8 ? 1 : 0;
	nb_pads = row_size % 4 ? 4 - row_size % 4 : 0;
	bitmap.img_size = (row_size + nb_pads) * bitmap.height;
	ft_bzero(bitmap.pads, nb_pads);
	create_bmp_file_header(file_header, bitmap.img_size);
	create_bmp_info_header(info_header, bitmap);
	if (write(fd, file_header, 14) == -1)
		return (EBFWF);
	if (write(fd, info_header, 40) == -1)
		return (EBFWF);
	while (bitmap.height--)
	{
		if (write(fd, bitmap.pixel_data + bitmap.height * bitmap.line_size, \
			row_size) == -1)
			return (EBFWF);
		if (write(fd, bitmap.pads, nb_pads) == -1)
			return (EBFWF);
	}
	return (0);
}
