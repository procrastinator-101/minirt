/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_reader.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:24:12 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/06 11:20:42 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	configuration_reader(char *input_file, void **entities)
{
	int		i;
	int		fd;
	int		er_nb;
	char	*line;
	char	*entity_name;

	fd = open(input_file, O_RDONLY);
	i = 1;
	while (i > 0)
	{
		if ((i = get_next_line(fd, &line)) < 0)
			manage_config_error(fd, line, entities, FILE_READING_ERROR);
		if (line && line[0] != '\n')
		{
			entity_name = malloc(3 * sizeof(char));
			if (!entity_name)
				manage_config_error(fd, line, entities, er_nb);
			ft_strlcpy(entity_name, line, 3);
			er_nb = get_entity_info(entity_name, entities, line);
			if (er_nb < 0)
				manage_config_error(fd, line, entities, er_nb);
		}
		free(line);
	}
	while (++i < ENTITIES_SIZE)
		print_entity(entities, i);
}
