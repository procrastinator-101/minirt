/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_entities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:04:13 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/01 10:42:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	destroy_entities(void **entities)
{
	int	i;

	i = 0;
	while (++i < DISPLAY)
	{
		if (i < CAMERA || i == ANTI_ALIASING)
			free(entities[i]);
		else if (i == CAMERA || i == LIGHT)
			ft_dclst_destroy(entities + i, i);
		else
			ft_lst_destroy(entities + i, i);
	}
	free(entities);
}
