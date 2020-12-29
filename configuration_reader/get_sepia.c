/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sepia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:52:23 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/29 11:24:50 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int	get_sepia(char *line, void **entities)
{
	int		start;
	int		holder;
	t_sepia	*sepia;

	sepia = entities[SEPIA];
	if (sepia->set)
		return (-EMSED);
	start = update_start(line, 2);
	if (start == -1)
		return (-SEPIA);
	sepia->on = ft_atoi_length(line + start, &holder);
	if (sepia->on != 0 && sepia->on != 1)
		return (-SEPIA);
	sepia->set = 1;
	return (check_end_entity_info(line, start + holder, SEPIA));
}
