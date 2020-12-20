/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:10:19 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/30 16:42:48 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_entity(void **entities, int type)
{
	if (type == RESOLUTION)
		print_resolution(entities[type]);
	else if (type == AMBIENT)
		print_ambient_light(entities[type]);
	else if (type == CAMERA)
		print_camera(entities[type]);
	else if (type == LIGHT)
		print_light(entities[type]);
	else if (type == SPHERE)
		print_sphere(entities[type]);
	else if (type == PLANE)
		print_plane(entities[type]);
	else if (type == SQUARE)
		print_square(entities[type]);
	else if (type == CYLINDER)
		print_cylinder(entities[type]);
	else if (type == TRIANGLE)
		print_triangle(entities[type]);
	else if (type == CONE)
		print_cone(entities[type]);
}
