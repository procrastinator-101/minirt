/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 21:29:17 by youness           #+#    #+#             */
/*   Updated: 2020/12/27 11:26:26 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	manage_translation(int key, t_camera *camera, void **entities)
{
	unsigned long long	type;
	t_coord_3d			v;

	v = null_3d_vec();
	type = (unsigned long long)entities[USER_OBJECT_TYPE];
	if (key == UP)
		v = camera->screen.w;
	else if (key == DOWN)
		v = scalar_product(camera->screen.w, -1);
	else if (key == RIGHT)
		v = camera->screen.u;
	else if (key == LEFT)
		v = scalar_product(camera->screen.u, -1);
	else if (key == PLUS)
		v = camera->screen.v;
	else if (key == MINUS)
		v = scalar_product(camera->screen.v, -1);
	else
		return ;
	entities[RENDER] = (void *)1;
	translate_object(entities[USER_OBJECT], v, type);
}
