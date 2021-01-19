/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:48:34 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/19 12:35:52 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

static int	fetch_user_grid_len(char *line, double *grid_len, int start)
{
	int	holder;
	int	new_start;

	if (!ft_isnumber(line + start))
		return (-2);
	*grid_len = ft_atod_length(line + start, &holder);
	new_start = update_start(line, start + holder);
	if (line[start + holder] && new_start == -1)
		return (-2);
	if (*grid_len < 0.0)
		return (-1);
	*grid_len = ft_max(*grid_len, 0.5);
	return (start + holder);
}

static int	get_grid_len(char *line, t_texture *texture, int start)
{
	int	new_start;

	new_start = update_start(line, start);
	if (new_start == -1)
		return (-1);
	new_start = fetch_user_grid_len(line, &(texture->grid_len), new_start);
	if (new_start == -2)
	{
		texture->grid_len = ft_min(texture->height, texture->width);
		if (texture->grid_len < 100.0)
			texture->grid_len /= 10.0;
		else
			texture->grid_len = 10.0;
		texture->grid_len = ft_max(texture->grid_len, 0.5);
		return (start);
	}
	return (new_start);
}

int			get_texture_color(char *line, t_texture *texture, int start)
{
	if ((start = fetch_rgb(line, &(texture->rgb1), start)) == -1)
		return (-1);
	if (texture->type[0] == CHECKERBOARD)
	{
		if ((start = update_start(line, start)) == -1)
			return (-1);
		if ((start = fetch_rgb(line, &(texture->rgb2), start)) == -1)
			return (-1);
		start = get_grid_len(line, texture, start);
	}
	return (start);
}
