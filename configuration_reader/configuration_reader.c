/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_reader.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:24:12 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 16:30:26 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int			main(int argc, char **argv)
{
	int		fd;
	int		nb_er;
	char	*line;
	char	*entity_name;
	void	**entities;

	if (!(entities = malloc(sizeof(void *) * 11)))
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '\n')
		{
			entity_name = malloc(3 * sizeof(char));
			if (!entity_name)
				manage_config_error(fd, line, entities);
			ft_strlcpy(entity_name, line, 3);
			if ((nb_er = get_entity_info(entity_name, entities, line) < 0)
				manage_config_error(fd, line, entities, nb_er);
		}
		free(line);
	}
}
