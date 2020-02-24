/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_reader.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:24:12 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/23 20:44:02 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	get_entity_name_info(char *entity_name, char *line, void **entities)
{
	if (!ft_strncmp(entity_name_name, "R", 2))
		get_resolution(line, entities);
	else if (!ft_strncmp(entity_name_name, "A", 2))
		get_ambient_light(line, entities);
	else if (!ft_strncmp(entity_name_name, "c", 2))
		get_camera(line, entities);
	else if (!ft_strncmp(entity_name_name, "l", 2))
		get_light(line, entities);
	else if (!ft_strncmp(entity_name_name, "sp", 2))
		get_sphere(line, entities);
	else if (!ft_strncmp(entity_name_name, "pl", 2))
		get_plane(line, entities);
	else if (!ft_strncmp(entity_name_name, "sq", 2))
		get_square(line, entities);
	else if (!ft_strncmp(entity_name_name, "cy", 2))
		get_cylinder(line, entities);
	else if (!ft_strncmp(entity_name_name, "tr", 2))
		get_triangle(line, entities);
}

int main(int argc, char **argv)
{
	int		fd;
	char	*entity_name;
	char	*str;
	char	*line;
	void	**entities;

	fd = open("config.rt", O_RDONLY);

	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '\n')
		{
			entity_name = malloc(3 * sizeof(char));
			if (!entity_name)
			{
				free(line);
				while (get_next_line(fd, &line) > 0)
					free(line);
				exit(1);
			}
			str = ft_memccpy(entity_name, line, ' ', 2);
			*(str - 1) = 0;
			get_entity_info(entity_name, line);
			free(line);
		}
	}

}
