/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entity_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:35:45 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/02 09:01:55 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static int	get_major_entities(char *line, void **entities)
{
	if (!ft_strncmp(line, "A", 1))
		return (get_ambient_light(line, entities));
	else if (!ft_strncmp(line, "c", 1))
		return (get_camera(line, entities));
	else if (!ft_strncmp(line, "l", 1))
		return (get_light(line, entities));
	else if (!ft_strncmp(line, "R", 1))
		return (get_resolution(line, entities));
	return (0);
}

static int	get_prim_info(char *line, void **entities, char *line)
{
	if (!ft_strncmp(line, "co", 2))
		return (get_cone(line, entities));
	else if (!ft_strncmp(line, "cu", 2))
		return (get_cube(line, entities));
	else if (!ft_strncmp(line, "cy", 2))
		return (get_cylinder(line, entities));
	else if (!ft_strncmp(line, "pl", 2))
		return (get_plane(line, entities));
	else if (!ft_strncmp(line, "py", 2))
		return (get_pyramid(line, entities));
	else if (!ft_strncmp(line, "sp", 2))
		return (get_sphere(line, entities));
	else if (!ft_strncmp(line, "sq", 2))
		return (get_square(line, entities));
	else if (!ft_strncmp(line, "tr", 2))
		return (get_triangle(line, entities));
	return (0);
}

static int	get_image_customizers(char *line, void **entities)
{
	if (!ft_strncmp(line, "AA", 2))
		return (get_anti_aliasing(line, entities));
	else if (!ft_strncmp(line, "SE", 2))
		return (get_sepia(line, entities));
	else if (!ft_strncmp(line, "SK", 2))
		return (get_skybox(line, entities));
	return (0);
}

int			get_entity_info(char *line, void **entities)
{
	int	ret;

	ret = get_prim_info(line, entities);
	if (!ret)
		ret = get_image_customizers(line, entities);
	if (!ret)
		ret = get_major_entities(line, entities);
	return (ret ? ret : -EUED);
}
