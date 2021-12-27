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
#include <bits/pthreadtypes.h>
#include <pthread.h>

static void	ft_locks_nclear(pthread_mutex_t *locks, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		pthread_mutex_destroy(locks + i);
}


static int	ft_initialise_locks(void **entities)
{
	int	i;
	int	error;

	entities[MUTEXES] = malloc(sizeof(pthread_mutex_t) * NB_BLOCKS);
	if (!entities[MUTEXES])
		return EMAF;
	i = -1;
	while (++i < NB_BLOCKS)
	{
		error = pthread_mutex_init(entities[MUTEXES] + i, 0);
		if (error)
		{
			ft_locks_nclear(entities[MUTEXES], i);
			return EMUCF;
		}
	}
	return 0;
}

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
