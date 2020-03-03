/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:10:19 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 19:42:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_entity(void **entities, int type)
{
	if (type == RESOLUTION)
		print_resolution(entities);
	else if (type == AMBIENT)
		print_ambient_light(entities);
	else if (type == CAMERA)
		print_camera(entities);
	else if (type == LIGHT)
		print_light(entities);
	else if (type == SPHERE)
		print_sphere(entities);
	else if (type == PLANE)
		print_plane(entities);
	else if (type == SQUARE)
		print_square(entities);
	else if (type == CYLINDER)
		print_cylinder(entities);
	else if (type == TRIANGLE)
		print_triangle(entities);
}
