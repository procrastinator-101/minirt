/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:10:19 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 17:24:45 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

static void	print_filters(void **entities, int type)
{
	if (type == SKYBOX)
		print_skybox(entities[type]);
	else if (type == SEPIA)
		print_sepia(entities[type]);
	else if (type == ANTI_ALIASING)
		print_anti_aliasing(entities[type]);
}

static void	print_prim_objects(void **entities, int type)
{
	if (type == SPHERE)
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

void		print_entity(void **entities, int type)
{
	if (type == RESOLUTION)
		print_resolution(entities[type]);
	else if (type == AMBIENT)
		print_ambient_light(entities[type]);
	else if (type == CAMERA)
		print_camera(entities[type]);
	else if (type == LIGHT)
		print_light(entities[type]);
	else if (type >= SPHERE && type <= CONE)
		print_prim_objects(entities, type);
	else if (type == CUBE)
		print_cube(entities[type]);
	else if (type == PYRAMID)
		print_pyramid(entities[type]);
	else
		print_filters(entities, type);
}
