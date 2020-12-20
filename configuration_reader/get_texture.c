/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:26:15 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/04 11:46:55 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int	get_texture(char *line, t_texture *texture, t_display *display, int type)
{
	int	start;

	if ((start = get_texture_type(line, texture->type, 0)) == -1)
		return (-type);
	if (texture->type[0] == UV_MAP)
	{
		start = get_texture_map(line, &(texture->uv_map), display, start);
		if (start == -1)
			return (-type);
	}
	else if (texture->type[0] == RGB || texture->type[0] == CHECKERBOARD)
	{
		start = get_texture_color(line, texture, start);
		if (start == -1)
			return (-type);
	}
	if (texture->type[1] == BUMP_MAP)
	{
		if ((start = update_start(line, start)) == -1)
			return (-type);
		start = get_texture_map(line, &(texture->bump_map), display, start);
		if (start == -1)
			return (-type);
	}
	return (check_end_entity_info(line, start, type));
}
