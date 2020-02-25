/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:48:33 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/25 17:45:00 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	fill_light_point(char *line, t_light *light, int start)
{
	int holder;

	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	light->light_point.x = ft_atod_length(line + start, &holder);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	light->light_point.y = ft_atod_length(line + start, &holder);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	light->light_point.z = ft_atod_length(line + start, &holder);
	return (start + holder);
}

static int	fill_rgb(char *line, t_light *light, int start)
{
	int holder;

	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	light->rgb.red = ft_atoi_length(line + start, &holder);
	if (light->rgb.red < 0 || light->rgb.red > 255)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	light->rgb.green = ft_atoi_length(line + start, &holder);
	if (light->rgb.green < 0 || light->rgb.green > 255)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	light->rgb.blue = ft_atoi_length(line + start, &holder);
	if (light->rgb.blue < 0 || light->rgb.blue > 255)
		return (-1);
	return (start + holder);
}

static int	fill_brightness(char *line, t_light *light, int start)
{
	int holder;

	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	light->brightness = ft_atod_length(line + start, &holder);
	if (light->brightness > 1.0)
		return (0);
	return (start + holder);
}

int			get_light(char *line, void **entities)
{
	int			start;
	int			holder;
	t_light		*light;

	if (!(light = malloc(sizeof(t_light))))
		return (0);
	//ft_lstadd_head(&(entities[LIGHT]), camera, LIGHT);
	entities[LIGHT] = light;
	light->next = 0;
	start = find_next_arg(line, 2);
	start = fill_light_point(line, light, start);
	if (start == -1)
		return (0);
	holder = find_next_arg(line, start);
	if (start == holder)
		return (0);
	start = fill_brightness(line, light, start);
	if (start == -1)
		return (0);
	holder = find_next_arg(line, start);
	if (holder == start)
		return (0);
	if (fill_rgb(line, light, start) == -1)
		return (0);
	return (1);
}
