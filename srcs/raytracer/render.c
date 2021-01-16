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

static void	*render_1_block(void *param)
{
	int		size;
	void	**entities;

	entities = (void **)param;
	size = (((t_resolution *)entities[RESOLUTION])->height + 3) / 4;
	render_block(entities, entities[USER_CAMERA], 0, size);
	return (0);
}

static void	*render_2_block(void *param)
{
	int		size;
	void	**entities;

	entities = (void **)param;
	size = (((t_resolution *)entities[RESOLUTION])->height + 3) / 4;
	render_block(entities, entities[USER_CAMERA], size, size * 2);
	return (0);
}

static void	*render_3_block(void *param)
{
	int		size;
	void	**entities;

	entities = (void **)param;
	size = (((t_resolution *)entities[RESOLUTION])->height + 3) / 4;
	render_block(entities, entities[USER_CAMERA], size * 2, size * 3);
	return (0);
}

static void	*render_4_block(void *param)
{
	int		height;
	void	**entities;

	entities = (void **)param;
	height = ((t_resolution *)entities[RESOLUTION])->height;
	render_block(entities, entities[USER_CAMERA], ((height + 3) / 4) * 3, \
		height);
	return (0);
}

void		render(void **entities)
{
	pthread_t	threads[4];

	if (pthread_create(threads, 0, render_1_block, (void *)entities))
		manage_exec_error(entities, ETCF);
	if (pthread_create(threads + 1, 0, render_2_block, (void *)entities))
		manage_exec_error(entities, ETCF);
	if (pthread_create(threads + 2, 0, render_3_block, (void *)entities))
		manage_exec_error(entities, ETCF);
	if (pthread_create(threads + 3, 0, render_4_block, (void *)entities))
		manage_exec_error(entities, ETCF);
	if (pthread_join(threads[0], 0))
		manage_exec_error(entities, ETJF);
	if (pthread_join(threads[1], 0))
		manage_exec_error(entities, ETJF);
	if (pthread_join(threads[2], 0))
		manage_exec_error(entities, ETJF);
	if (pthread_join(threads[3], 0))
		manage_exec_error(entities, ETJF);
}
