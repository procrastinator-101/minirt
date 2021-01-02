/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_configuration.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:38:03 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/02 12:42:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	parse_configuration(void **entities, int fd)
{
	int		i;
	int		er_nb;
	char	*line;

	er_nb = 0;
	i = 1;
	while (i > 0)
	{
		if ((i = get_next_line(fd, &line)) < 0)
			manage_config_error(fd, line, entities, -EIFRE);
		if (line && line[0])
		{
			printf("\nline	: %s||\n\n", line);
			er_nb = get_entity_info(line, entities);
			if (er_nb < 0)
				manage_config_error(fd, line, entities, er_nb);
		}
		free(line);
	}
}
