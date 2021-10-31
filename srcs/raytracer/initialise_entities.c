/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_entities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:39:21 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/31 17:42:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	**initialise_entities(void)
{
	int		i;
	void	**entities;

	if (!(entities = malloc(sizeof(void *) * ENTITIES_SIZE)))
	{
		display_error_message(EMAF);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < ENTITIES_SIZE)
		entities[i] = 0;
	return (entities);
}
