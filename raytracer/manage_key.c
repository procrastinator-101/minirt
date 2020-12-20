/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 13:10:00 by youness           #+#    #+#             */
/*   Updated: 2020/11/04 20:11:49 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

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
	else if (key == A)
	{
		entities[USER_OBJECT] = entities[ANTI_ALIASING];
        entities[USER_OBJECT_TYPE] = (void *)ANTI_ALIASING;
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
			entities[USER_CAMERA] = ((t_camera *)entities[USER_CAMERA])->previous;
		entities[USER_OBJECT] = entities[USER_CAMERA];
		entities[RENDER] = (void *)1;
	}
}

static void	update_aa_factor(void **entities, int *aa_factor, int key)
{
	if (key == PLUS)
		*aa_factor += 1;
	else if (key == MINUS)
		*aa_factor -= 1;
	if (*aa_factor > 10)
		*aa_factor = 10;
	else if (*aa_factor < 1)
		*aa_factor = 1;
	entities[RENDER] = (void *)1;
}

int	manage_key(int key, void *param)
{
	int			caps;
	void		**entities;

	entities = (void **)param;
	printf("key = %d\n", key);
	printf("user object type = %llu\n", (unsigned long long)entities[USER_OBJECT_TYPE]);
	if (key == ESC)
		exit(EXIT_SUCCESS);
	else if (key == N || key == P)
		traverse_hidden_objects(entities, key);
	else if (key == C || key == L || key == A)
		select_hidden_objects(entities, key);
	else if (key == S)
	{
		*(int *)(entities[SEPIA]) = !(*(int *)(entities[SEPIA]));
		entities[RENDER] = (void *)1;
	}
	else if (key == O && entities[USER_OBJECT_TYPE] == (void *)CYLINDER)//xor
	{
		caps = ((t_cylinder *)(entities[USER_OBJECT]))->caps;
		((t_cylinder *)(entities[USER_OBJECT]))->caps = !caps;
		entities[RENDER] = (void *)1;
	}
	else if (entities[USER_OBJECT_TYPE] == (void *)ANTI_ALIASING && \
		(key == MINUS || key == PLUS))
		update_aa_factor(entities, entities[ANTI_ALIASING], key);
	else if (key >= ONE && key <= NINE)
		manage_rotation(key, entities[USER_CAMERA], entities);
	else
		manage_translation(key, entities[USER_CAMERA], entities);
	ft_print_object_position(entities[USER_CAMERA], CAMERA);
	ft_print_object_position(entities[USER_OBJECT], \
		(int)entities[USER_OBJECT_TYPE]);
	if ((int)entities[USER_OBJECT_TYPE] == PYRAMID)
	{
		printf("apex : ");
		print_coord_3d(((t_pyramid *)entities[USER_OBJECT])->apex);
		printf("basis : ");
		print_coord_3d(((t_pyramid *)entities[USER_OBJECT])->base->position);
	}
	if (entities[RENDER])
		raytracer(entities[USER_CAMERA], entities, entities[DISPLAY]);
	return (0);
}
