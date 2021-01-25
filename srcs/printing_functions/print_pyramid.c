/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pyramid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:00:16 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/25 16:06:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

static void	print_base(t_square *square)
{
	printf("***** BASE  *****\n");
	print_coord_3d(square->position);
	printf("radius = %f\n", square->radius);
	print_3d_basis(square->basis);
	print_texture(&(square->texture));
}

static void	print_pyramid_faces(t_pyramid *pyramid)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		printf("***** face %d *****\n", i);
		print_coord_3d(pyramid->faces[i]->p1);
		print_coord_3d(pyramid->faces[i]->p2);
		print_coord_3d(pyramid->faces[i]->p3);
		print_coord_3d(pyramid->faces[i]->c);
		print_coord_3d(pyramid->faces[i]->centroid);
		print_3d_basis(pyramid->faces[i]->basis);
		print_texture(&(pyramid->faces[i]->texture));
	}
}

void		print_pyramid(t_pyramid *pyramid)
{
	while (pyramid)
	{
		printf("\n\n=====================================");
		printf(" PYRAMID ");
		printf("======================================\n");
		printf("apex\t:\t");
		print_coord_3d(pyramid->apex);
		print_texture(&(pyramid->texture));
		print_base(pyramid->base);
		print_pyramid_faces(pyramid);
		printf("==========================================");
		printf("==========================================\n");
		pyramid = pyramid->next;
	}
}
