/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:45:42 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 11:54:21 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_cube(t_cube *cube)
{
	int	i;

	while (cube)
	{
		printf("\n\n=========== CUBE  ===========\n");
		print_coord_3d(cube->center);
		printf("radius\t=\t%f\n", cube->radius);
		print_3d_basis(cube->basis);
		print_texture(&(cube->texture));
		i = -1;
		while (++i < 6)
		{
			printf("***** face %d *****\n", i);
			print_coord_3d(cube->faces[i]->position);
			printf("radius = %f\n", cube->faces[i]->radius);
			print_3d_basis(cube->faces[i]->basis);
			print_texture(&(cube->faces[i]->texture));
		}
		cube = cube->next;
	}
}
