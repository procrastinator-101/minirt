/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:57:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 21:37:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	get_color(t_ray ray, void **entities, int endian)
{
	int				color;
	t_rgb			rgb;
	t_intersection	closest_inter;
	
	closest_inter = get_closest_inter(ray, entities);
	rgb.red = 0;
	rgb.green = 0;
	rgb.blue = 0;
	if (closest_inter.distance == INFINITY)
		return (rgb_to_int(rgb, endian));
	rgb = get_object_rgb(closest_inter.object, closest_inter.type);
	color = rgb_to_int(rgb, endian);
	return (color);
}
