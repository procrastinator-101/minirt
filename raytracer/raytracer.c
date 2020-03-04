/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:39:51 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/04 17:57:03 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int	raytracer(t_camera *camera, void **entities)
{
	int			i;
	int			j;
	t_ray		ray;
	t_point_3d	start;

	ray.origin = camera->postion;
	start.x = camera->postion.x - camera->screen.width;
	start.y = camera->postion.y + camera->screen.height;
	start.z = camera->postion.z + 1;
	ray.direction.z = start.z;
	i = 0;
	while (++i < entities[RESOLUTION]->height)
	{
		j = 0;
		while (++j < entities[RESOLUTION]->width)
		{
			ray.direction.x = start.x + j * camera->pixel.width;
			ray.direction.y = start.y - i * camera->pixel.height;
			pixels[i - 1][j - 1] = get_color(ray, entities);
		}
	}
}
