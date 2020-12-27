/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_object_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:45:15 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/27 11:59:38 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	handle_object_mode(void **entities, int key)
{
	if (key == O && entities[USER_OBJECT_TYPE] == (void *)CYLINDER)
	{
		((t_cylinder *)(entities[USER_OBJECT]))->caps ^= 1;
		entities[RENDER] = (void *)1;
	}
	else if (key == M && entities[USER_OBJECT_TYPE] == (void *)SPHERE)
	{
		if (((t_sphere *)entities[USER_OBJECT])->mode == STATIC_MODE)
			((t_sphere *)entities[USER_OBJECT])->mode = INTERACTIVE_MODE;
		else
			((t_sphere *)entities[USER_OBJECT])->mode = STATIC_MODE;
		update_sphere_mode(entities[USER_OBJECT]);
		entities[RENDER] = (void *)1;
	}
}
