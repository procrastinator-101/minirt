/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_reader.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:24:12 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/16 17:14:29 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void		configuration_reader(char *input_file, void **entities)
{
	int		i;
	int		fd;
	int		er_nb;

	fd = open(input_file, O_RDONLY);
	if (fd == -1)
		manage_exec_error(entities, EIFRF);
	parse_configuration(entities, fd);
	if (close(fd) == -1)
		manage_exec_error(entities, EIFCF);
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
