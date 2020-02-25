/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:48:33 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/25 15:48:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	fill_light_point(char *line, t_light *light, int start)
{
	int	holder;

	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	light->light_point.x = basic_atod(line + start, &holder);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	light->light_point.y = basic_atod(line + start, &holder);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	light->light_point.z = basic_atod(line + start, &holder);
	start += holder;
	return (start);
}

static int	fill_rgb(char *line, t_light *light, int start)
{
	if (!ft_isdigit(line[start] && line[start] != 43))
		return (-1);
	light->red = ft_atoi(line + start);
	if (light->red > 255)
		return (-1);
	
}

int		get_light(char *line, void **entities)
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
	start = find_next_arg(line, start);
	if (!ft_isdigit(line[start]))
		return (0);
	light->brightness = basic_atod(line + start, &holder);
	if (light->brightness > 1.0)
		return (0);
	start = find_next_arg(line, start + holder);
	start = fill_rgb(line, light, start);
	if (start == -1)
		return (0);
	return (1);
}
