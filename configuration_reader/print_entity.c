/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:10:19 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 18:15:25 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_entity(void **entities, int type)
{
	if (type == RESOLUTION)
		print_resolution(entities);
	else if (error_number == AMBIENT)
		print_ambient_light(entities);
	else if (error_number == CAMERA)
		print_camera(entities);
	else if (error_number == LIGHT)
		print_light(entities);
	else if (error_number == SPHERE)
		print_sphere(entities);
	else if (error_number == PLANE)
		print_plane(entities);
	else if (error_number == SQUARE)
		print_square(entities);
	else if (error_number == CYLINDER)
		print_cylinder(entities);
	else if (error_number == TRIANGLE)
		print_triangle(entities);
}
