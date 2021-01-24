/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:13:30 by youness           #+#    #+#             */
/*   Updated: 2021/01/24 15:12:58 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	manage_rotation(int key, t_camera *camera, void **entities)
{
	unsigned long long	type;
	t_smat_3d			m;

	m = null_3d_smat();
	type = (unsigned long long)entities[USER_OBJECT_TYPE];
	if (key == SIX)
		m = get_rotation_matrix(ROTATION_ANGLE, camera->screen.w);
	else if (key == FOUR)
		m = get_rotation_matrix(-ROTATION_ANGLE, camera->screen.w);
	else if (key == EIGHT)
		m = get_rotation_matrix(-ROTATION_ANGLE, camera->screen.u);
	else if (key == TWO)
		m = get_rotation_matrix(ROTATION_ANGLE, camera->screen.u);
	else if (key == THREE || key == NINE)
		m = get_rotation_matrix(ROTATION_ANGLE, camera->screen.v);
	else if (key == ONE || key == SEVEN)
		m = get_rotation_matrix(-ROTATION_ANGLE, camera->screen.v);
	else
		return ;
	entities[RENDER] = (void *)1;
	rotate_object(entities[USER_OBJECT], m, type);
}
