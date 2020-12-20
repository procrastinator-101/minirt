/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_reader.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:24:12 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/22 13:54:12 by yarroubi         ###   ########.fr       */
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
			manage_config_error(fd, line, entities, EFR);
		if (line && line[0] != '\n')
		{
			entity_name = malloc(3 * sizeof(char));
			if (!entity_name)
				manage_config_error(fd, line, entities, EMA);
			ft_strlcpy(entity_name, line, 3);
			er_nb = get_entity_info(entity_name, entities, line);
			if (er_nb < 0)
				manage_config_error(fd, line, entities, er_nb);
		}
		free(line);
	}
	close(fd);
	er_nb = check_critical_entities(entities);
	if (er_nb)
		manage_exec_error(entities, er_nb);
	get_screen_pixel(entities);
	er_nb = construct_cubes(entities[CUBE], entities);
	if (er_nb)
		manage_exec_error(entities, er_nb);
	er_nb = construct_pyramids(entities[PYRAMID], entities);
        if (er_nb)
                manage_exec_error(entities, er_nb);
	i = 0;
	while (++i < CUBE)
		print_entity(entities, i);
}
