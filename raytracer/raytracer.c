/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:39:51 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 19:39:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int	raytracer(t_camera *camera, void **entities, t_display *display)
{
	int			i;
	int			j;
	int			width;
	t_ray		ray;
	t_point_3d	start;

	width = entities[RESOLUTION]->width;
	ray.origin = camera->postion;
	start = get_left_corner(camera, camera->screen);
	ray.direction.z = start.z;
	i = -1;
	while (++i < entities[RESOLUTION]->height)
	{
		j = -1;
		while (++j < width)
		{
			ray.direction.x = start.x + j * camera->pixel.width;
			ray.direction.y = start.y - i * camera->pixel.height;
			display->img_addr[i * width + j] = get_color(ray, entities, \
				display->endian);
		}
	}
	mlx_put_image_to_window(display->mlx_ptr, display->win_ptr, \
		display->img_ptr, 0, 0);
}
