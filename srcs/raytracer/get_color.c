/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:57:56 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/31 15:11:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	get_color(t_ray ray, void **entities)
{
	t_rgb			rgb;
	t_coord_3d		p;
	t_intersection	closest_inter;

	closest_inter = get_closest_inter(ray, entities);
	rgb = get_black_rgb();
	if (closest_inter.distance != INFINITY)
		rgb = illuminate(closest_inter, entities, ray);
	else if (entities[SKYBOX])
	{
		closest_inter = intersect_skybox(ray, entities[SKYBOX]);
		p = coord_3d_add(ray.origin, scalar_product(ray.direction, \
			closest_inter.distance));
		rgb = get_rgb_square(closest_inter.object, p);
	}
	if (((t_sepia *)entities[SEPIA])->on)
		rgb = rgb_to_sepia(rgb);
	return (adjust_rgb(rgb));
}
