/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:21:14 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/30 16:53:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_sphere(t_sphere *sphere)
{
	while (sphere)
	{
		printf("\n\n=========== SPHERE  ===========\n");
		print_coord_3d(sphere->center);
		printf("radius = %f\n", sphere->radius);
		print_texture(&(sphere->texture));
		printf("\n\n");
		sphere = sphere->next;
	}
}
