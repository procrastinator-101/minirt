/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:21:14 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/03 10:03:51 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	display_element(t_sphere *sphere)
{
	if (!sphere)
		return ;
	print_point_3d(sphere->sphere_point);
	printf("diameter = %f\n", sphere->diameter);
	print_rgb(sphere->rgb);
	printf("\n\n");
	display_element(sphere->next);
}

void		print_sphere(void **entities)
{
	t_sphere	*sphere;

	sphere = entities[SPHERE];
	printf("\n\n===========	SPHERE	===========\n");
	display_element(sphere);
}
