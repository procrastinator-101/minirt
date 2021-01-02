/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:48:33 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/02 09:58:51 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static int	get_brightness(char *line, t_light *light, int start)
{
	int holder;

	if (!ft_isdigit(line[start]) && !ft_issign(line[start]))
		return (-1);
	light->brightness = ft_atod_length(line + start, &holder);
	if (light->brightness > 1.0 || light->brightness < 0.0)
		return (-1);
	return (start + holder);
}

int			get_light(char *line, void **entities)
{
	int			start;
	t_light		*light;

	if (!(light = malloc(sizeof(t_light))))
		return (-EMAF);
	ft_dclst_add_head(entities + LIGHT, light, LIGHT);
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
