/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 10:45:05 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/01 11:40:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	*render_block(void *param)
{
	int		size;
	void	**entities;

	entities = (void **)param;
	size = (((t_resolution *)entities[RESOLUTION])->height + 3) / 4;
	render_block(entities, entities[USER_CAMERA], 0, size);
	return (0);
}

void		render(void **entities)
{
	int			i;
	pthread_t	threads[NB_BLOCKS];

	i = -1;
	while (++i < NB_BLOCKS)
	{
		if (pthread_create(threads, 0, render_block, (void *)entities))
			manage_exec_error(entities, ETCF);
	}
	i = -1;
	while (++i < NB_BLOCKS)
	{
		if (pthread_join(threads[0], 0))
			manage_exec_error(entities, ETCF);
	}
}
