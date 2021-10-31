/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_object_class.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:23:40 by yarroubi          #+#    #+#             */
/*   Updated: 2020/04/25 18:56:00 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersection.h"

t_intersection	intersect_object_class(t_ray ray, void *class_tail, int type)
{
	double			distance;
	t_intersection	closest_inter;

	closest_inter.distance = INFINITY;
	closest_inter.object = class_tail;
	closest_inter.type = type;
	while (class_tail)
	{
		distance = get_intersection(ray, class_tail, type);
		if (distance < closest_inter.distance && distance >= 0.0)
		{
			closest_inter.distance = distance;
			closest_inter.object = class_tail;
		}
		class_tail = get_next_lst_mem(class_tail, type);
	}
	return (closest_inter);
}
