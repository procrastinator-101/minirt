/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sepia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:52:23 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/01 19:00:17 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int	get_sepia(char *line, void **entities)
{
	int start;
	int	holder;
	int	*sepia;

	sepia = entities[SEPIA];
	start = update_start(line, 2);
	if (start == -1)
		return (-SEPIA);
	*sepia = ft_atoi_length(line + start, &holder);
	if (*sepia != 0 && *sepia != 1)
		return (-SEPIA);
	return (check_end_entity_info(line, start + holder, SEPIA));
}
