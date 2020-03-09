/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:23:40 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/09 18:23:16 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_intersection	intersect(t_ray ray, void *class_tail, int type)
{
	void			*next;
	double          distance;
	t_intersection  closest_inter;

	closest_inter.distance = INFINITY;
	closest_inter.object = class_tail;
	closest_inter.type = type;
	if (class_tail)
	{
		distance = get_intersection(ray, class_tail, type);
		if (distance < INFINITY && distance >= 0.0)
			closest_inter.distance = distance;
		next = choose_entity_type(class_tail, type);
		while (next != class_tail)
		{
			distance = get_intersection(ray, next, type);
			if (distance < closest_inter.distance && distance >= 0.0)
			{
				closest_inter.distance = distance;
				closest_inter.object = next;
			}
			next = choose_entity_type(next, type);
		}
	}
	return (closest_inter);
}
