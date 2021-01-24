/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_object_position.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:44:26 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/28 12:52:26 by yarroubi         ###   ########.fr       */
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
		printf("position : ");
		print_coord_3d(((t_light *)object)->position);
	}
}

static void	handle_primary_objects(void *object, int type)
{
	if (type == SPHERE)
	{
		printf("\n\n===========     SPHERE       ===========\n");
		printf("center : ");
		print_coord_3d(((t_sphere *)object)->center);
	}
	else if (type == PLANE)
	{
		printf("\n\n===========     PLANE       ===========\n");
		printf("position : ");
		print_coord_3d(((t_plane *)object)->position);
	}
	else if (type == SQUARE)
	{
		printf("\n\n===========     SQUARE       ===========\n");
		printf("position : ");
		print_coord_3d(((t_square *)object)->position);
	}
	else if (type == CYLINDER)
	{
		printf("\n\n===========     CYLINDER       ===========\n");
		printf("position : ");
		print_coord_3d(((t_cylinder *)object)->position);
	}
}

static void	handle_compound_objects(void *object, int type)
{
	if (type == CUBE)
	{
		printf("\n\n===========     CUBE       ===========\n");
		printf("center : ");
		print_coord_3d(((t_cube *)object)->center);
	}
	else if (type == PYRAMID)
	{
		printf("\n\n===========     PYRAMID       ===========\n");
		printf("apex : ");
		print_coord_3d(((t_pyramid *)object)->apex);
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
		printf("p1 : ");
		print_coord_3d(((t_triangle *)object)->p1);
		printf("p2 : ");
		print_coord_3d(((t_triangle *)object)->p2);
		printf("p3 : ");
		print_coord_3d(((t_triangle *)object)->p3);
	}
	else if (type == CONE)
	{
		printf("\n\n===========     CONE       ===========\n");
		printf("vertex : ");
		print_coord_3d(((t_cone *)object)->vertex);
	}
	else if (type == CUBE || type == CONE)
		handle_compound_objects(object, type);
}
