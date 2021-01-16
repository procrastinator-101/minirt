/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:39:51 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/01 11:45:01 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	raytracer(t_camera *camera, void **entities, t_display *display)
{
	int			nb;

	nb = *((int *)entities[ANTI_ALIASING]);
	camera->pixel.u = scalar_product(camera->screen.u, camera->pixel.width);
	camera->pixel.v = scalar_product(camera->screen.v, camera->pixel.height);
	camera->sub_pixel.width = camera->pixel.width / nb;
	camera->sub_pixel.height = camera->pixel.height / nb;
	camera->sub_pixel.u = scalar_product(camera->screen.u, \
		camera->sub_pixel.width);
	camera->sub_pixel.v = scalar_product(camera->screen.v, \
		camera->sub_pixel.height);
	if (entities[SKYBOX])
		translate_skybox(entities[SKYBOX], camera);
	render(entities);
	if (entities[SAVE_IMAGE])
		save_image(entities, display->img_addr);
	else
		mlx_put_image_to_window(display->mlx_ptr, display->win_ptr, \
			display->img_ptr, 0, 0);
}
