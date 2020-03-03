/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:08:03 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 20:22:54 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	display_element(t_light *light)
{
	if (!light)
		return ;
	print_point_3d(light->light_point);
	printf("brightness = %f\n", light->brightness);
	print_rgb(light->rgb);
	display_element(light->next);
}

void		print_light(void **entities)
{
	t_light	*light;

	light = entities[LIGHT];
	printf("\n\n===========	LIGHT	===========\n");
	display_element(light);
}
