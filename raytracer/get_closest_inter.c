/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_inter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:15:50 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/09 16:05:41 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_intersection	get_closest_inter(t_ray ray, void **entities)
{
	int				i;
	t_intersection	closest_inter;
	t_intersection	temp;

	closest_inter.distance = INFINITY;
	i = CAMERA;
	while (++i < DISPLAY)
	{
		temp = intersect(ray, entities[i], i);
		if (temp.distance < closest_inter.distance)
			closest_inter = temp;
	}
	return (closest_inter);
}
