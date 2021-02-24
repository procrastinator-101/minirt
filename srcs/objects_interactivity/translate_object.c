/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 20:58:51 by youness           #+#    #+#             */
/*   Updated: 2021/02/24 16:25:30 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	translate_object(void *object, t_coord_3d v, int type)
{
	if (type == CAMERA)
		translate_camera(object, v);
	else if (type == LIGHT)
		translate_light(object, v);
	else if (type == SPHERE)
		translate_sphere(object, v);
	else if (type == PLANE)
		translate_plane(object, v);
	else if (type == SQUARE)
		translate_square(object, v);
	else if (type == CYLINDER)
		translate_cylinder(object, v);
	else if (type == TRIANGLE)
		translate_triangle(object, v);
	else if (type == CONE)
		translate_cone(object, v);
	else if (type == DISK)
		translate_disk(object, v);
	else if (type == CUBE)
		translate_cube(object, v);
	else if (type == PYRAMID)
		translate_pyramid(object, v);
}
