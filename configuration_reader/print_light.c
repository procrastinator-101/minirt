/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:08:03 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/30 16:58:08 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_light(t_light *light)
{
	t_light	*tail;

	if (!light)
		return ;
	tail = light;
	while (light)
	{
		printf("\n\n===========	LIGHT	===========\n");
		print_coord_3d(light->position);
		printf("brightness = %f\n", light->brightness);
		print_rgb(light->rgb);
		light = light->next != tail ? light->next : 0;
	}
}
