/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_config_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:38:29 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/02 11:16:50 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	manage_config_error(int fd, char *line, void **entities, int er_nb)
{
	printf("\n\nline	: %s||\n\n", line);
	free(line);
	if (er_nb != -EIFRE)
	{
		while (get_next_line(fd, &line) > 0)
			free(line);
	}
	close(fd);
	destroy_entities(entities);
	display_error_message(-er_nb);
	exit(EXIT_FAILURE);
}
