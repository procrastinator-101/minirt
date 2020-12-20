/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_light_blocked.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:57:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 21:37:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	is_light_blocked(t_ray ray, void **entities)
{
	int		i;
	double	temp;

	i = LIGHT;
	while (++i < DISPLAY)
	{
		temp = intersect_obstacle_class(ray, entities[i], i);
		if (temp < 1.0)
			return (1);
	}
	return (0);
}
