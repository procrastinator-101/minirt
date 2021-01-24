/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:21:14 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 16:46:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_sphere(t_sphere *sphere)
{
	while (sphere)
	{
		printf("\n\n======================================");
		printf(" SPHERE ");
		printf("======================================\n");
		print_coord_3d(sphere->center);
		printf("radius = %f\n", sphere->radius);
		printf("mode = %c\n", sphere->mode);
		print_3d_basis(sphere->basis);
		print_texture(&(sphere->texture));
		printf("==========================================");
		printf("==========================================\n");
		sphere = sphere->next;
	}
}
