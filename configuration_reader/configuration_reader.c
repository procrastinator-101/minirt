/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_reader.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:24:12 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/05 18:21:04 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int			main(int argc, char **argv)
{
	int		i;
	int		fd;
	int		er_nb;
	char	*line;
	char	*entity_name;
	void	**entities;

	if (argc < 2)
		return (0);
	if (!(entities = malloc(sizeof(void *) * ENTITIES_SIZE)))
		return (0);
	i = -1;
	while (++i < ENTITIES_SIZE)
		entities[i] = 0;
	fd = open(argv[1], O_RDONLY);
	i = 1;
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		if (i < 0)
			return (0);
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
	return (0);
}
