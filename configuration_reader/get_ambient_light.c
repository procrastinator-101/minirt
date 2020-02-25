/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:50:58 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/25 16:55:25 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	fetch_rgb(char *line, t_ambient *ambient_light, int start)
{
	int holder;

	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	ambient_light->rgb.red = ft_atoi_length(line + start, &holder);
	if (ambient_light->rgb.red < 0 || ambient_light->rgb.red > 255)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	ambient_light->rgb.green = ft_atoi_length(line + start, &holder);
	if (ambient_light->rgb.green < 0 || ambient_light->rgb.green > 255)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	ambient_light->rgb.blue = ft_atoi_length(line + start, &holder);
	if (ambient_light->rgb.blue < 0 || ambient_light->rgb.blue > 255)
		return (-1);
	return (start + holder);
}

int			get_ambient_light(char *line, void **entities)
{
	int			start;
	int			holder;
	t_ambient	*ambient_light;

	if (entities[AMBIENT])
		return (0);
	if (!(ambient_light = malloc(sizeof(t_ambient))))
		return (0);
	entities[AMBIENT] = (void *)ambient_light;
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
