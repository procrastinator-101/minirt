/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:41:34 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/09 18:52:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	get_intersection(t_ray ray, void *class, int type)
{
	double	distance;

	distance = INFINITY;
	if (type == SPHERE)
		distance = intersect_sphere(ray, class);
	else if (type == PLANE)
		distance = intersect_plane(ray, class);
	else if (type == SQUARE)
		distance = intersect_square(ray, class);
	/*else if (type == CYLINDER)
		distance = intersect_cylinder(ray, class);
	else if (type == TRIANGLE)
		distance = intersect_plane(ray, class);
	*/return (distance);
}
