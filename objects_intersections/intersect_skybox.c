/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_skybox.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 10:25:40 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/08 10:40:37 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_intersection	intersect_skybox(t_ray ray, t_skybox *skybox)
{
	int				i;
	double			dist;
	t_intersection	hit;

	hit.distance = intersect_square(ray, &(skybox->faces[0]));
	hit.object = &(skybox->faces[0]);
	i = 0;
	while (++i < 6)
	{
		dist = intersect_square(ray, &(skybox->faces[i]));
		if (dist < hit.distance)
		{
			hit.distance = dist;
			hit.object = &(skybox->faces[i]);
		}
	}
	return (hit);
}
