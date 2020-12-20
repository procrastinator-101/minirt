/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:48:34 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/05 19:47:50 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int	get_texture_color(char *line, t_texture *texture, int start)
{
	if ((start = fetch_rgb(line, &(texture->rgb1), start)) == -1)
		return (-1);
	if (texture->type[0] == CHECKERBOARD)
	{
		if ((start = update_start(line, start)) == -1)
			return (-1);
		if ((start = fetch_rgb(line, &(texture->rgb2), start)) == -1)
			return (-1);
		if (!line[start])
		{
			texture->grid_len = ft_min(texture->height, texture->width);
			if (texture->grid_len < 100.0)
				texture->grid_len /= 10.0;
			else
				texture->grid_len = 10.0;
			texture->grid_len = ft_max(texture->grid_len, 0.5);
		}
		else
		{
			if ((start = update_start(line, start)) == -1)
				return (-1);
			if ((start = get_grid_len(line, &(texture->grid_len), start)) == -1)
				return (-1);
		}
	}
	return (start);
}
