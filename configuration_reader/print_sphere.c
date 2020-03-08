/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:21:14 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/08 12:05:03 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void		print_sphere(void **entities)
{
	t_sphere	*sphere;

	sphere = entities[SPHERE];
	if (!sphere)
		return ;
	printf("\n\n===========	SPHERE	===========\n");
	print_coord_3d(sphere->center);
	printf("diameter = %f\n", sphere->radius);
	print_rgb(sphere->rgb);
	printf("\n\n");
	sphere = sphere->next;
	while (sphere != entities[SPHERE])
	{
		printf("\n\n=========== SPHERE  ===========\n");
		print_coord_3d(sphere->center);
		printf("diameter = %f\n", sphere->radius);
		print_rgb(sphere->rgb);
		printf("\n\n");
		sphere = sphere->next;
	}
}
