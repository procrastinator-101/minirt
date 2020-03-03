/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_config_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:38:29 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/03 09:32:12 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	manage_config_error(int fd, char *line, void **entities, int er_nb)
{
	int	i;

	printf("\n==> line | %s |\n", line);
	free(line);
	while (get_next_line(fd, &line) > 0)
		free(line);
	i = 0;
	while (++i < 10)
	{
		if (i < 3)
			free(entities[i]);
		else
			ft_lst_destroy(entities + i, i);
	}
	free(entities);
	display_error_message(-er_nb);
	exit(1);
}
