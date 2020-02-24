/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:50:58 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/24 18:46:28 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	fetch_ratio(char *line, t_ambient *ambient_light, int start)
{
	int	holder;
	int	length;

	holder = ft_atoi(line + 2);
	if (holder > 1 || !ft_isdigit(line[2]))
		return (-1);
	length = 1;
	if (line[3] == '.')
	{
		if (!ft_isdigit(line[4]))
			return (-1);
		ambient_light->ratio = ft_atoi(line + 4);
		if (holder && ambient_light->ratio > 0.0)
			return (-1);
		length++;
	}
	if (ambient_light->ratio != 0.0)
		start = (int)log10(ambient_light->ratio) + 1;
	else
		start = line[3] == '.';
	ambient_light->ratio /= pow(10.0, start);
	ambient_light->ratio += holder;
	return (start + length);
}

static int	fetch_rgb(char *line, t_ambient *ambient_light, int start)
{
	if (!ft_isdigit(line[start]))
		return (-1);
	ambient_light->red = ft_atoi(line + start);
	if (ambient_light->red > 255 || ambient_light->red < 0)
		return (-1);
	start += (int)log10(ambient_light->red) + 1;
	if (line[start] != ',' || !ft_isdigit(line[++start]))
		return (-1);
	ambient_light->green = ft_atoi(line + start);
	if (ambient_light->green < 0 || ambient_light->green > 255)
		return (-1);
	start += (int)log10(ambient_light->green) + 1;
	if (line[start] != ',' || !ft_isdigit(line[++start]))
		return (-1);
	ambient_light->blue = ft_atoi(line + start);
	if (ambient_light->blue < 0 || ambient_light->blue > 255)
		return (-1);
	return (1);
}

int			get_ambient_light(char *line, void **entities)
{
	int			start;
	t_ambient	*ambient_light;

	if (!(ambient_light = malloc(sizeof(t_ambient))))
		return (0);
	entities[1] = (void *)ambient_light;
	start = fetch_ratio(line, ambient_light, start);
	if (start == -1)
		return (0);
	if (fetch_rgb(line, ambient_light, start + 3) == -1)
		return (0);
	return (1);
}
