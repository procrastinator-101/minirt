/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_entities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:04:13 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 18:29:09 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	destroy_entities(void **entities)
{
	int	i;

	i = 0;
	while (++i < ENTITIES_SIZE)
	{
		if (i < CAMERA)
			free(entities[i]);
		else
			ft_lst_destroy(entities + i, i);
	}
	free(entities);
}
