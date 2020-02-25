/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_reader.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:24:12 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/25 17:50:52 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	get_entity_info(char *entity_name, void **entities, char *line)
{
	int	ret;

	ret = 0;
	if (!ft_strncmp(entity_name, "R", 2))
		ret = get_resolution(line, entities);
	else if (!ft_strncmp(entity_name, "A", 2))
		ret = get_ambient_light(line, entities);
	else if (!ft_strncmp(entity_name, "c", 2))
		ret = get_camera(line, entities);
	else if (!ft_strncmp(entity_name, "l", 2))
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

static void	manage_config_error(int fd, char *line, void **entities)
{
	free(line);
	while (get_next_line(fd, &line) > 0)
		free(line);
	exit(1);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	*entity_name;
	void	**entities;

	fd = open("config.rt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '\n')
		{
			entity_name = malloc(3 * sizeof(char));
			if (!entity_name)
				manage_config_error(fd, line, entities);
			ft_strlcpy(entity_name, line, 3);
			if (!get_entity_info(entity_name, entities, line))
				manage_config_error(fd, line, entities);
		}
		free(line);
	}
}
