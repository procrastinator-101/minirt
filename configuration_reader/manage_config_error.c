/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_config_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:38:29 by yarroubi          #+#    #+#             */
/*   Updated: 2020/06/22 15:09:04 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	manage_config_error(int fd, char *line, void **entities, int er_nb)
{
	free(line);
	while (get_next_line(fd, &line) > 0)
		free(line);
	close(fd);
	destroy_entities(entities);
	display_error_message(-er_nb);
	exit(EXIT_FAILURE);
}
