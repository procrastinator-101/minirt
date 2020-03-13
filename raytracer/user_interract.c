/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:59:59 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/10 15:49:02 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static int manage_key(int key, void *param)
{
	void		**entities;
	t_camera	*camera;

	entities = (void **)param;
	camera = entities[USER_CAMERA];
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 126)
		camera->position = coord_3d_plus(camera->position, camera->screen.w);
	else if (key == 125)
		camera->position = coord_3d_minus(camera->position, camera->screen.w);
	else if (key == 124)
		camera->position = coord_3d_plus(camera->position, camera->screen.u);
	else if (key == 123)
		camera->position = coord_3d_minus(camera->position, camera->screen.u);
	else if (key == 91)
		camera->position = coord_3d_plus(camera->position, camera->screen.v);
	else if (key == 84)
		camera->position = coord_3d_minus(camera->position, camera->screen.v);
	else if (key == 45)
		camera = camera->next;
	else if (key == 35)
		camera = camera->previous;
	entities[USER_CAMERA] = camera;
	print_coord_3d(camera->position);
	raytracer(camera, entities, entities[DISPLAY]);
	return (0);
}

void	user_interract(void **entities, t_display *display)
{
	mlx_hook(display->win_ptr, KeyPress, KeyPressMask, &manage_key, entities);
	mlx_loop(display->mlx_ptr);
}
