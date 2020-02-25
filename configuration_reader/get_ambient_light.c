/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:50:58 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/25 12:19:36 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

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
	int			holder;
	t_ambient	*ambient_light;

	if (entities[1])
		return (0);
	if (!(ambient_light = malloc(sizeof(t_ambient))))
		return (0);
	entities[1] = (void *)ambient_light;
	start = find_next_arg(line, 2);
	if (!ft_isdigit(line[start]))
		return (0);
	ambient_light->ratio = basic_atod(line + start, &holder);
	if (ambient_light->ratio < 0.0 || ambient_light->ratio > 1.0)
		return (0);
	start = find_next_arg(line, start + holder);
	if (start == holder)
		return (0);
	if (fetch_rgb(line, ambient_light, start) == -1)
		return (0);
	return (1);
}
