/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:50:58 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/02 09:57:14 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int	get_ambient_light(char *line, void **entities)
{
	int			start;
	int			holder;
	t_ambient	*ambient_light;

	if (entities[AMBIENT])
		return (-EMAD);
	if (!(ambient_light = malloc(sizeof(t_ambient))))
		return (-EMAF);
	entities[AMBIENT] = ambient_light;
	start = update_start(line, 1);
	if (start == -1)
		return (-AMBIENT);
	if (!ft_isdigit(line[start]) && !ft_issign(line[start]))
		return (-AMBIENT);
	ambient_light->ratio = ft_atod_length(line + start, &holder);
	if (ambient_light->ratio < 0.0 || ambient_light->ratio > 1.0)
		return (-AMBIENT);
	start = update_start(line, start + holder);
	if (start == -1)
		return (-AMBIENT);
	start = fetch_rgb(line, &(ambient_light->rgb), start);
	return (check_end_entity_info(line, start, AMBIENT));
}
