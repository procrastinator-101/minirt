/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hidden_objects.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:38:18 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/27 11:45:01 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	select_hidden_objects(void **entities, int key)
{
	if (key == C)
	{
		entities[USER_OBJECT] = entities[USER_CAMERA];
		entities[USER_OBJECT_TYPE] = (void *)CAMERA;
	}
	else if (key == L)
	{
		entities[USER_OBJECT] = entities[USER_LIGHT];
		entities[USER_OBJECT_TYPE] = (void *)LIGHT;
	}
	entities[RENDER] = (void *)0;
}

static void	traverse_hidden_objects(void **entities, int key)
{
	if (entities[USER_OBJECT_TYPE] == (void *)LIGHT)
	{
		if (key == N)
			entities[USER_LIGHT] = ((t_light *)entities[USER_LIGHT])->next;
		else
			entities[USER_LIGHT] = ((t_light *)entities[USER_LIGHT])->previous;
		entities[USER_OBJECT] = entities[USER_LIGHT];
		entities[RENDER] = (void *)0;
	}
	else
	{
		if (key == N)
			entities[USER_CAMERA] = ((t_camera *)entities[USER_CAMERA])->next;
		else
			entities[USER_CAMERA] = ((t_camera *)entities[USER_CAMERA])->\
				previous;
		if (entities[USER_OBJECT_TYPE] == (void *)CAMERA)
			entities[USER_OBJECT] = entities[USER_CAMERA];
		entities[RENDER] = (void *)1;
	}
}

void		handle_hidden_objects(void **entities, int key)
{
	if (key == N || key == P)
		traverse_hidden_objects(entities, key);
	else if (key == C || key == L)
		select_hidden_objects(entities, key);
}
