/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_configuration.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:38:03 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/27 17:44:46 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	parse_configuration(void **entities, int fd)
{
	int		i;
	int		er_nb;
	char	*line;
	char	*entity_name;

	er_nb = 0;
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
}
