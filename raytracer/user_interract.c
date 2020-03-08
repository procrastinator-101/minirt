/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:59:59 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/08 14:21:26 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static int manage_key(int key, void *param)
{
	void		**entities;
	t_camera	*camera;

	entities = (void **)param;
	camera = entities[CAMERA];
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 126)
		camera->position.z++;
	else if (key == 125)
		camera->position.z--;
	else if (key == 124)
		camera->position.x--;
	else if (key == 123)
		camera->position.x++;
	else if (key == 91)
		camera->position.y++;
	else if (key == 84)
		camera->position.y--;
	print_coord_3d(camera->position);
	raytracer(camera, entities, entities[DISPLAY]);
	return (0);
}

void	user_interract(void **entities, t_display *display)
{
	mlx_key_hook(display->win_ptr, &manage_key, entities);
	mlx_loop(display->mlx_ptr);
}
