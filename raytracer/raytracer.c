/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:39:51 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/08 10:05:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

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
	render_block(entities, entities[USER_CAMERA], ((height + 3) / 4) * 3, height);
	return (0);
}

int			raytracer(t_camera *camera, void **entities, t_display *display)
{
	int			nb;
	pthread_t	threads[4];

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
	pthread_create(threads, 0, render_1_block, (void *)entities);
	pthread_create(threads + 1, 0, render_2_block, (void *)entities);
	pthread_create(threads + 2, 0, render_3_block, (void *)entities);
	pthread_create(threads + 3, 0, render_4_block, (void *)entities);
	nb = -1;
	while (++nb < 4)
		pthread_join(threads[nb], 0);
	if (entities[SAVE_IMAGE])
		save_image(entities, entities[SAVE_IMAGE], (char *)display->img_addr);//image name
	else
		mlx_put_image_to_window(display->mlx_ptr, display->win_ptr, \
				display->img_ptr, 0, 0);
	return (0);
}
