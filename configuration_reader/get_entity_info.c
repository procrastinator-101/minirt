/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entity_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:35:45 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/27 17:26:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static int	get_major_entities(char *entity_name, void **entities, char *line)
{
	if (!ft_strncmp(entity_name, "A", 1))
		return (get_ambient_light(line, entities));
	else if (!ft_strncmp(entity_name, "c", 1))
		return (get_camera(line, entities));
	else if (!ft_strncmp(entity_name, "l", 1))
		return (get_light(line, entities));
	else if (!ft_strncmp(entity_name, "R", 1))
		return (get_resolution(line, entities));
	return (0);
}

static int	get_prim_info(char *entity_name, void **entities, char *line)
{
	if (!ft_strncmp(entity_name, "co", 2))
		return (get_cone(line, entities));
	else if (!ft_strncmp(entity_name, "cu", 2))
		return (get_cube(line, entities));
	else if (!ft_strncmp(entity_name, "cy", 2))
		return (get_cylinder(line, entities));
	else if (!ft_strncmp(entity_name, "pl", 2))
		return (get_plane(line, entities));
	else if (!ft_strncmp(entity_name, "py", 2))
		return (get_pyramid(line, entities));
	else if (!ft_strncmp(entity_name, "sp", 2))
		return (get_sphere(line, entities));
	else if (!ft_strncmp(entity_name, "sq", 2))
		return (get_square(line, entities));
	else if (!ft_strncmp(entity_name, "tr", 2))
		return (get_triangle(line, entities));
	return (0);
}

static int	get_image_customizers(char *entity_name, void **entities, \
			char *line)
{
	if (!ft_strncmp(entity_name, "aa", 2))
		return (get_anti_aliasing(line, entities));
	else if (!ft_strncmp(entity_name, "se", 2))
		return (get_sepia(line, entities));
	else if (!ft_strncmp(entity_name, "sk", 2))
		return (get_skybox(line, entities));
	return (0);
}

int			get_entity_info(char *entity_name, void **entities, char *line)
{
	int	ret;

	ret = get_prim_info(entity_name, entities, line);
	if (!ret)
		ret = get_major_entities(entity_name, entities, line);
	if (!ret)
		ret = get_image_customizers(entity_name, entities, line);
	free(entity_name);
	return (ret);
}
