/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illuminate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/22 14:25:36 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	illuminate(t_intersection hit, void **entities, t_ray ray)
{
	t_ray		l;
	t_coord_3d	p;
	t_coord_3d	n;
	t_light		*light;
	t_rgb		phong_rgb;

	light = entities[LIGHT];
	phong_rgb = get_black_rgb();
	p = coord_3d_plus(ray.origin, scalar_product(ray.direction, hit.distance));
	n = surface_normal(hit.object, ray.direction, p, hit.type);
	l.origin = coord_3d_plus(p, scalar_product(n, EPSILON));
	while (light)
	{
		if (light->brightness > 0.0)
		{
			l.direction = coord_3d_minus(light->position, l.origin);
			if (!is_light_blocked(l, entities))
				phong_rgb = rgb_sum(phong_rgb, diffuse_spec_terms(l, \
					n, ray.direction, light));
		}
		light = light->next != entities[LIGHT] ? light->next : 0;
	}
	phong_rgb = rgb_sum(phong_rgb, ambient_term(entities[AMBIENT]));
	phong_rgb = rgb_mul_rgb(phong_rgb, get_object_rgb(hit.object, p, \
		hit.type));
	return (phong_rgb);
}
