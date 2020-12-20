/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:48:33 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/21 11:40:49 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static int	get_brightness(char *line, t_light *light, int start)
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
	t_light		*light;

	if (!(light = malloc(sizeof(t_light))))
		return (-LIGHT);
	ft_dclst_add_head(entities + LIGHT, light, LIGHT);
	light->next = entities[LIGHT];
	start = update_start(line, 1);
	if (start == -1)
		return (-LIGHT);
	start = fetch_point_3d(line, &(light->position), start);
	start = update_start(line, start);
	if (start == -1)
		return (-LIGHT);
	start = get_brightness(line, light, start);
	start = update_start(line, start);
	if (start == -1)
		return (-LIGHT);
	start = fetch_rgb(line, &(light->rgb), start);
	return (check_end_entity_info(line, start, LIGHT));
}
