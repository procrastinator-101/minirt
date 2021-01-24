/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:46:28 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 12:53:39 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_triangle(t_triangle *triangle)
{
	while (triangle)
	{
		if (!triangle->parent)
		{
			printf("\n\n=========== TRIANGLE        ===========\n");
			printf("p1\t:\t");
			print_coord_3d(triangle->p1);
			printf("p2\t:\t");
			print_coord_3d(triangle->p2);
			printf("p3\t:\t");
			print_coord_3d(triangle->p3);
			printf("c\t:\t");
			print_coord_3d(triangle->c);
			printf("centroid\t:\t");
			print_coord_3d(triangle->centroid);
			print_3d_basis(triangle->basis);
			print_texture(&(triangle->texture));
		}
		triangle = triangle->next;
	}
}
