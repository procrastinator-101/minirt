/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_obstacle_class.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:57:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 21:37:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersection.h"

double	intersect_obstacle_class(t_ray ray, void *class_tail, int type)
{
	double	distance;

	distance = INFINITY;
	while (class_tail)
	{
		distance = get_intersection(ray, class_tail, type);
		if (distance < 1.0 && distance >= 0.0)
			return (distance);
		class_tail = get_next_lst_mem(class_tail, type);
	}
	return (distance);
}
