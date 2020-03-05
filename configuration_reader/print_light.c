/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:08:03 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/05 17:12:39 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_light(void **entities)
{
	t_light	*light;

	light = entities[LIGHT];
	if (!light)
		return ;
	printf("\n\n===========	LIGHT	===========\n");
	print_coord_3d(light->light_point);
	printf("brightness = %f\n", light->brightness);
	print_rgb(light->rgb);
	light = light->next;
	while (light != entities[LIGHT])
	{
		printf("\n\n===========	LIGHT	===========\n");
		print_coord_3d(light->light_point);
		printf("brightness = %f\n", light->brightness);
		print_rgb(light->rgb);
		light = light->next;
	}
}
