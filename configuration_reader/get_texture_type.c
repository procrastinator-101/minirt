/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:49:15 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/25 14:17:31 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static int	is_texture_type(char c)
{
	if (c == RGB)
		return (1);
	if (c == CHECKERBOARD)
		return (1);
	if (c == UV_MAP)
		return (1);
	return (0);
}

int			get_texture_type(char *line, char *texture_type, int start)
{
	texture_type[0] = line[start];
	texture_type[1] = 0;
	if (!is_texture_type(texture_type[0]))
		return (-1);
	if (line[start + 1] == BUMP_MAP)
	{
		texture_type[1] = BUMP_MAP;
		start++;
	}
	else if (line[start + 1] == WAVE)
	{
		texture_type[1] = WAVE;
		start++;
	}
	return (update_start(line, start + 1));
}
