/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_object_position.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:44:26 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/25 17:02:36 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

static void	handle_hidden_objects(void *object, int type)
{
	if (type == CAMERA)
	{
		printf("\n\n===========     CAMERA      ===========\n");
		printf("position : \n");
		print_coord_3d(((t_camera *)object)->position);
		printf("basis 	 : \n");
		print_coord_3d(((t_camera *)object)->screen.u);
		print_coord_3d(((t_camera *)object)->screen.v);
		print_coord_3d(((t_camera *)object)->screen.w);
	}
	else if (type == LIGHT)
	{
		printf("\n\n===========     LIGHT       ===========\n");
		print_coord_3d(((t_light *)object)->position);
	}
}

static void	handle_primary_objects(void *object, int type)
{
	if (type == SPHERE)
	{
		printf("\n\n===========     SPHERE       ===========\n");
		print_coord_3d(((t_sphere *)object)->center);
	}
	else if (type == PLANE)
	{
		printf("\n\n===========     PLANE       ===========\n");
		print_coord_3d(((t_plane *)object)->position);
	}
	else if (type == SQUARE)
	{
		printf("\n\n===========     SQUARE       ===========\n");
		print_coord_3d(((t_square *)object)->position);
	}
	else if (type == CYLINDER)
	{
		printf("\n\n===========     CYLINDER       ===========\n");
		print_coord_3d(((t_cylinder *)object)->position);
	}
}

static void	handle_compound_objects(void *object, int type)
{
	if (type == CUBE)
	{
		printf("\n\n===========     CUBE       ===========\n");
		print_coord_3d(((t_cube *)object)->center);
	}
	else if (type == PYRAMID)
	{
		printf("\n\n===========     PYRAMID       ===========\n");
		print_coord_3d(((t_pyramid *)object)->base->position);
	}
}

void		ft_print_object_position(void *object, int type)
{
	if (type == CAMERA || type == LIGHT)
		handle_hidden_objects(object, type);
	else if (type >= SPHERE && type < TRIANGLE)
		handle_primary_objects(object, type);
	else if (type == TRIANGLE)
	{
		printf("\n\n===========     TRIANGLE       ===========\n");
		print_coord_3d(((t_triangle *)object)->p1);
		print_coord_3d(((t_triangle *)object)->p2);
		print_coord_3d(((t_triangle *)object)->p3);
	}
	else if (type == CONE)
	{
		printf("\n\n===========     CONE       ===========\n");
		print_coord_3d(((t_cone *)object)->vertex);
	}
	else if (type == DISK)
	{
		printf("\n\n===========     DISK       ===========\n");
		print_coord_3d(((t_disk *)object)->position);
	}
	else if (type == CUBE || type == CONE)
		handle_compound_objects(object, type);
}
