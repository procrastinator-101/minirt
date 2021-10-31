/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_inter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:15:50 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/25 16:36:49 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersection.h"

t_intersection	get_closest_inter(t_ray ray, void **entities)
{
	int				i;
	t_intersection	closest_inter;
	t_intersection	temp;

	closest_inter.distance = INFINITY;
	i = LIGHT;
	while (++i < CUBE)
	{
		temp = intersect_object_class(ray, entities[i], i);
		if (temp.distance < closest_inter.distance)
			closest_inter = temp;
	}
	return (closest_inter);
}
