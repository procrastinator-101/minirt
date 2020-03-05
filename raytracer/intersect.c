/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:23:40 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/04 20:52:39 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_intersection	intersect(t_ray ray, void *object, int type)
{
	t_intersection temp;

	temp.distance = INFINITY;
	else if (type == SPHERE)
		temp = intersect_sphere(ray, object);
	else if (type == PLANE)
		temp = intersect_plane(ray, object);
	else if (type == SQUARE)
		temp = intersect_square(ray, object);
	else if (type == CYLINDER)
		temp = intersect_cylinder(ray, object);
	else if (type == TRIANGLE)
		temp = intersect_plane(ray, object);
	return (temp);
}
