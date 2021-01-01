/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:03:26 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/01 12:23:11 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static int	extract_map_file(char *file_name, t_map *map, t_display *display, \
			int offset)
{
	int	width;
	int	height;
	int	endian;

	if (!ft_strcmp(file_name + offset, "xpm"))
		map->img_ptr = mlx_xpm_file_to_image(display->mlx_ptr, file_name, \
			&width, &height);
	else if (!ft_strcmp(file_name + offset, "png"))
		map->img_ptr = mlx_png_file_to_image(display->mlx_ptr, file_name, \
			&width, &height);
	else
		return (-EMFWE);
	if (!map->img_ptr)
		return (-EMPEF);
	map->img_addr = mlx_get_data_addr(map->img_ptr, &(map->bpp), \
		&(map->line_size), &endian);
	if (!map->img_addr)
		return (-EMPICF);
	map->u_scale = map->width / width;
	map->v_scale = map->height / height;
	map->width = width;
	map->height = height;
	return (0);
}

int			get_texture_map(char *line, t_map *map, t_display *display, \
		int start)
{
	int			i;
	int			ext;
	int			ret;
	char		*file_name;

	ext = 0;
	i = start;
	while (line[i] && ((line[i] < 8 || line[i] > 11) && line[i] != 32))
	{
		if (line[i] == '.')
			ext = i;
		i++;
	}
	if (ext == 0)
		return (-EMFME);
	if (!(file_name = ft_substr(line, start, i - start)))
		return (-EMAF);
	ret = extract_map_file(file_name, map, display, ext - start + 1);
	free(file_name);
	return (ret < 0 ? ret : i);
}
