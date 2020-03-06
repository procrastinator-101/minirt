/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_entities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:04:13 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/06 12:19:36 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	destroy_entities(void **entities)
{
	int	i;
	int j;

	i = 0;
	while (++i < ENTITIES_SIZE)
	{
		if (i < CAMERA)
			free(entities[i]);
		else if (i == PIXELS)
			destroy_pixels(entities[PIXELS]);
		else
			ft_lst_destroy(entities + i, i);
	}
	free(entities);
}
