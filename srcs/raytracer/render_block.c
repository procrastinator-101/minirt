/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:24:21 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 12:56:43 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	render_block(void **entities, t_camera *camera, int start, int end)
{
	int			i;
	int			j;
	t_ray		ray;
	t_coord_3d	p;
	t_coord_3d	tmp;

	i = start - 1;
	ray.origin = camera->position;
	p = get_left_corner(camera, camera->screen);
	p = coord_3d_sub(p, scalar_product(camera->pixel.v, start));
	while (++i < end)
	{
		j = -1;
		tmp = p;
		while (++j < ((t_resolution *)entities[RESOLUTION])->width)
		{
			ray.direction = tmp;
			update_pixel_data(entities[DISPLAY], j, i, render_pixel(entities, \
				camera, ray));
			tmp = coord_3d_add(tmp, camera->pixel.u);
		}
		p = coord_3d_sub(p, camera->pixel.v);
	}
}
