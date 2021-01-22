/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 13:10:00 by youness           #+#    #+#             */
/*   Updated: 2020/12/27 12:55:06 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	manage_key(int key, void *param)
{
	void		**entities;

	entities = (void **)param;
	if (key == ESC)
		exit(EXIT_SUCCESS);
	else if (key == N || key == P || key == C || key == L)
		handle_hidden_objects(entities, key);
	else if (key == S || key == A || (entities[USER_OBJECT_TYPE] == (void *)\
		ANTI_ALIASING && (key == MINUS || key == PLUS)))
		handle_filters(entities, key);
	else if (key == O || key == M)
		handle_object_mode(entities, key);
	else
	{
		manage_rotation(key, entities[USER_CAMERA], entities);
		manage_translation(key, entities[USER_CAMERA], entities);
	}
	//print_camera(entities[USER_CAMERA]);
	//printf("object_type = %llu\n", (unsigned long long)entities[USER_OBJECT_TYPE]);
	ft_print_object_position(entities[USER_OBJECT], \
			(int)entities[USER_OBJECT_TYPE]);
	if (entities[RENDER])
		raytracer(entities[USER_CAMERA], entities, entities[DISPLAY]);
	return (0);
}