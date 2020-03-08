/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:39:51 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/08 14:21:01 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	raytracer(t_camera *camera, void **entities, t_display *display)
{
	int			i;
	int			j;
	int			width;
	t_ray		ray;
	t_coord_3d	start;

	width = ((t_resolution *)entities[RESOLUTION])->width;
	ray.origin = camera->position;
	start = get_left_corner(camera, camera->screen);
	ray.direction.z = start.z;
	i = -1;
	while (++i < ((t_resolution *)entities[RESOLUTION])->height)
	{
		ray.direction.y = start.y - i * camera->pixel.height;
		j = -1;
		while (++j < width)
		{
			ray.direction.x = start.x + j * camera->pixel.width;
			//print_coord_3d(ray.direction);
			display->img_addr[i * width + j] = get_color(ray, entities, \
				display->endian);
		}
	}
	mlx_put_image_to_window(display->mlx_ptr, display->win_ptr, \
		display->img_ptr, 0, 0);
	return (0);
}
