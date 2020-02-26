/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:21:14 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 18:26:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	display_element(t_sphere *sphere)
{
	if (!sphere)
		return ;
	print_point_3d(sphere->sphere_point);
	printf("diameter = %f\n", sphere->diameter);
	print_rgb(sphere->rgb);
	display_element(sphere->next);
}

void	print_sphere(void **entities)
{
	t_sphere	*sphere;

	sphere = entities[SPHERE];
	display_element(sphere);
}
