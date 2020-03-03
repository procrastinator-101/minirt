/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entity_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:35:45 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 20:23:52 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int	get_entity_info(char *entity_name, void **entities, char *line)
{
	int ret;

	ret = 0;
	if (!ft_strncmp(entity_name, "R ", 2))
		ret = get_resolution(line, entities);
	else if (!ft_strncmp(entity_name, "A ", 2))
		ret = get_ambient_light(line, entities);
	else if (!ft_strncmp(entity_name, "c ", 2))
		ret = get_camera(line, entities);
	else if (!ft_strncmp(entity_name, "l ", 2))
		ret = get_light(line, entities);
	else if (!ft_strncmp(entity_name, "sp", 2))
		ret = get_sphere(line, entities);
	else if (!ft_strncmp(entity_name, "pl", 2))
		ret = get_plane(line, entities);
	else if (!ft_strncmp(entity_name, "sq", 2))
		ret = get_square(line, entities);
	else if (!ft_strncmp(entity_name, "cy", 2))
		ret = get_cylinder(line, entities);
	else if (!ft_strncmp(entity_name, "tr", 2))
		ret = get_triangle(line, entities);
	free(entity_name);
	return (ret);
}
