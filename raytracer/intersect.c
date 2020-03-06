/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:23:40 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/06 12:32:21 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_intersection	intersect(t_ray ray, void *class, int type)
{
	t_intersection temp;

	temp.distance = INFINITY;
	if (type == SPHERE)
		temp = intersect_sphere(ray, class);
	/*else if (type == PLANE)
		temp = intersect_plane(ray, class);
	else if (type == SQUARE)
		temp = intersect_square(ray, class);
	else if (type == CYLINDER)
		temp = intersect_cylinder(ray, class);
	else if (type == TRIANGLE)
		temp = intersect_plane(ray, class);
	*/return (temp);
}
