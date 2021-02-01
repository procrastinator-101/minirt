/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mouse_hits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 13:12:22 by youness           #+#    #+#             */
/*   Updated: 2021/02/01 14:25:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	update_user_object(t_intersection hit, void **entities)
{
	unsigned long long	type;

	if (hit.distance == INFINITY)
	{
		entities[USER_OBJECT] = entities[USER_CAMERA];
		entities[USER_OBJECT_TYPE] = (void *)CAMERA;
	}
	else
	{
		entities[USER_OBJECT] = hit.object;
		type = hit.type;
		if (hit.type == SQUARE && ((t_square *)hit.object)->parent)
		{
			entities[USER_OBJECT] = ((t_square *)hit.object)->parent;
			type = ((t_square *)hit.object)->parent_type;
		}
		else if (hit.type == TRIANGLE && ((t_triangle *)hit.object)->parent)
		{
			entities[USER_OBJECT] = ((t_triangle *)hit.object)->parent;
			type = PYRAMID;
		}
		entities[USER_OBJECT_TYPE] = (void *)type;
	}
}

int			manage_mouse_hits(int button, int x, int y, void *param)
{
	void			**entities;
	t_ray			ray;
	t_camera		*camera;
	t_coord_3d		v;
	t_intersection	hit;

	if (button == 2)
		return (0);
	entities = param;
	camera = entities[USER_CAMERA];
	ray.origin = camera->position;
	ray.direction = get_left_corner(camera, camera->screen);
	v = scalar_product(camera->screen.u, x * camera->pixel.width);
	ray.direction = coord_3d_add(ray.direction, v);
	v = scalar_product(camera->screen.v, y * camera->pixel.height);
	ray.direction = coord_3d_sub(ray.direction, v);
	ray.direction = coord_3d_sub(ray.direction, ray.origin);
	hit = get_closest_inter(ray, entities);
	update_user_object(hit, entities);
	return (0);
}
