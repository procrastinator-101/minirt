/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_inter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:15:50 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/04 18:22:36 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_intersection	get_closest_inter(t_ray ray, void **entity_name)
{
	int				i;
	t_intersection	closest_inter;
	t_intersection	temp;

	closest_inter.distance = DBL_MAX;
	i = CAMERA - 1;
	while (++i < ENTITIES_SIZE)
	{
		temp = intersect(ray, entities[i], i);
		if (temp.distance < closest_inter.distance)
			closest_inter = temp;
	}
	return (closest_inter);
}
