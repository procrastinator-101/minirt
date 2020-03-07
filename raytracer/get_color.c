/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:57:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 18:24:34 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int	get_color(t_ray ray, void **entities, int endian)
{
	int				color;
	t_rgb			rgb;
	t_intersection	closest_inter;
	
	closest_inter = get_closest_inter(ray, entities);
	rbg.red = 0;
	rgb.green = 0;
	rgb.blue = 0;
	if (closest_inter.distance == INFINITY || closest_inter.distance < 0)
		return (rgb_to_int(rgb, endian));
	rgb = get_object_rgb(closest_inter.object, closest_inter.type);
	color = rgb_to_int(rgb, endian);
	return (color);
}
