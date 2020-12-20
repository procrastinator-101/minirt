/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:58:16 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/31 19:18:39 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	get_object_rgb(void *object, t_coord_3d p, int type)
{
	if (type == LIGHT)
		return (((t_light *)object)->rgb);
	if (type == SPHERE)
		return (get_rgb_sphere(object, p));
	if (type == PLANE)
		return (get_rgb_plane(object, p));
	if (type == SQUARE)
		return (get_rgb_square(object, p));
	if (type == CYLINDER)
		return (get_rgb_cylinder(object, p));
	if (type == TRIANGLE)
		return (get_rgb_triangle(object, p));
	return (get_rgb_cone(object, p));
}
