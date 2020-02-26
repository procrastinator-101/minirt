/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_config_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:38:29 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 15:43:20 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void manage_config_error(int fd, char *line, void **entities)
{
	free(line);
	while (get_next_line(fd, &line) > 0)
		free(line);
	exit(1);
}
