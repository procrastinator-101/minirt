/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_anti_aliasing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:30:47 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/01 19:00:39 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int	get_anti_aliasing(char *line, void **entities)
{
	int start;
	int	holder;
	int	*aa_factor;

	aa_factor = entities[ANTI_ALIASING];
	start = update_start(line, 2);
	if (start == -1)
		return (-ANTI_ALIASING);
	*aa_factor = ft_atoi_length(line + start, &holder);
	if (*aa_factor < 0)
		return (-ANTI_ALIASING);
	if (*aa_factor > 10)
		*aa_factor = 10;
	return (check_end_entity_info(line, start + holder, ANTI_ALIASING));
}
