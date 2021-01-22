/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_config_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:38:29 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/22 14:38:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	manage_config_error(int fd, char *line, void **entities, int er_nb)
{
	char	*str;

	if (er_nb != -EIFRE)
	{
		while (get_next_line(fd, &str) > 0)
			free(str);
	}
	close(fd);
	destroy_entities(entities);
	display_error_message(-er_nb);
	if (er_nb != -EIFRE)
		printf("\n\nline	: ||%s||\n\n", line);
	free(line);
	exit(EXIT_FAILURE);
}
