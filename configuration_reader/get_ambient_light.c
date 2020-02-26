/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:50:58 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 15:43:52 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int			get_ambient_light(char *line, void **entities)
{
	int			start;
	int			holder;
	t_ambient	*ambient_light;

	if (entities[AMBIENT])
		return (-AMBIENT);
	if (!(ambient_light = malloc(sizeof(t_ambient))))
		return (-AMBIENT);
	entities[AMBIENT] = (void *)ambient_light;
	start = find_next_arg(line, 2);
	if (!ft_isdigit(line[start]))
		return (-AMBIENT);
	ambient_light->ratio = ft_atod_length(line + start, &holder);
	if (ambient_light->ratio < 0.0 || ambient_light->ratio > 1.0)
		return (-AMBIENT);
	start = find_next_arg(line, start + holder);
	if (start == holder)
		return (-AMBIENT);
	if (fetch_rgb(line, &(ambient_light->rgb), start) == -1)
		return (-AMBIENT);
	return (AMBIENT);
}
