/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:03:26 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/08 16:57:10 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int	get_texture_map(char *line, t_map *map, t_display *display, \
		int start)
{
	int			i;
	int			e;
	int			width;
	int			height;
	int			endian;
	char		*file_name;

	e = 0;
	i = start;
	while (line[i] && ((line[i] < 8 || line[i] > 11) && line[i] != 32))
	{
		if (line[i] == '.')
			e = i;
		i++;
	}
	if (e == 0)
		return (-1);//Error map file extension
	if (!(file_name = ft_substr(line, start, i - start)))
		return (-1);//EMF
	if (!ft_strcmp(file_name + e - start + 1, "xpm"))
		map->img_ptr = mlx_xpm_file_to_image(display->mlx_ptr, file_name, \
			&width, &height);
	else if (!ft_strcmp(file_name + e - start + 1, "png"))
		map->img_ptr = mlx_png_file_to_image(display->mlx_ptr, file_name, \
			&width, &height);
	else
	{
		free(file_name);
		return (-1);//Error map file extension
	}
	free(file_name);
	if (!map->img_ptr)
		return (-1);//MLX MAP EXTRACTION ERROR
	map->img_addr = mlx_get_data_addr(map->img_ptr, &(map->bpp), \
		&(map->line_size), &endian);
	if (!map->img_addr)
		return (-1);//mlx image creation error
	map->u_scale = map->width / width;
	map->v_scale = map->height / height;
	map->width = width;
	map->height = height;
	return (i);
}
