/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_bmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 14:09:38 by youness           #+#    #+#             */
/*   Updated: 2020/12/23 12:48:06 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static char	*create_bmp_file_header(int img_size)
{
	char	*header;

	if (!(header = malloc(14 * sizeof(char))))
		return (0);
	header[0] = 'B';
	header[1] = 'M';
	convert_to_lit_end(header + 2, 54 + img_size, 4);
	ft_bzero(header + 6, 4);
	convert_to_lit_end(header + 10, 54, 4);
	return (header);
}


static char	*create_bmp_info_header(t_bitmap bitmap)
{
	char		*header;

	if (!(header = malloc(40 * sizeof(char))))
		return (0);
	convert_to_lit_end(header, 40, 4);
	convert_to_lit_end(header + 4, bitmap.width, 4);
	convert_to_lit_end(header + 8, bitmap.height, 4);
	convert_to_lit_end(header + 12, 1, 2);
	convert_to_lit_end(header + 14, bitmap.bpp, 2);
	ft_bzero(header + 16, 4);
	convert_to_lit_end(header + 20, 0, 4);
	convert_to_lit_end(header + 24, 20000, 4);//monitpr
	convert_to_lit_end(header + 28, 20000, 4);//
	ft_bzero(header + 32, 8);
	return (header);
}

int			image_to_bmp(t_bitmap bitmap, int fd)
{
	int		nb_pads;
	int		img_size;
	char	pads[3];
	char	*file_header;
	char	*info_header;

	nb_pads = bitmap.line_size % 4 ? 4 - bitmap.line_size % 4 : 0;
	img_size = (bitmap.line_size + nb_pads) * bitmap.height;
	ft_bzero(pads, nb_pads);
	printf("image size = %d\n", img_size);
	if (!(file_header = create_bmp_file_header(img_size)))
		return (EMA);
	if (!(info_header = create_bmp_info_header(bitmap)))
	{
		free(file_header);
		return (EMA);
	}
	write(fd, file_header, 14);
	write(fd, info_header, 40);
	free(file_header);
	free(info_header);
	while (bitmap.height--)
	{
		write(fd, bitmap.pixel_data + bitmap.height * bitmap.line_size, bitmap.line_size);
		write(fd, pads, nb_pads);
	}
	return (0);
}
