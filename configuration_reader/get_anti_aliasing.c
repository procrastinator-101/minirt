/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_anti_aliasing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:30:47 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/02 08:17:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int	get_anti_aliasing(char *line, void **entities)
{
	int				start;
	int				holder;
	t_anti_aliasing	*anti_aliasing;

	if (entities[ANTI_ALIASING])
		return (-EMAAD);
	if (!(anti_aliasing = malloc(sizeof(t_anti_aliasing))))
		return (-EMAF);
	start = update_start(line, 2);
	if (start == -1)
		return (-ANTI_ALIASING);
	anti_aliasing->factor = ft_atoi_length(line + start, &holder);
	if (anti_aliasing->factor < 1)
		return (-ANTI_ALIASING);
	if (anti_aliasing->factor > MAX_AA_FACTOR)
		anti_aliasing->factor = MAX_AA_FACTOR;
	return (check_end_entity_info(line, start + holder, ANTI_ALIASING));
}
