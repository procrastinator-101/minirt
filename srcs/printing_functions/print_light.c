/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:08:03 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 16:48:33 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_light(t_light *light)
{
	t_light	*tail;

	if (!light)
		return ;
	tail = light;
	while (light)
	{
		printf("\n\n======================================");
		printf(" LIGHT ");
		printf("=======================================\n");
		print_coord_3d(light->position);
		printf("brightness = %f\n", light->brightness);
		print_rgb(light->rgb);
		printf("==========================================");
		printf("==========================================\n");
		light = light->next != tail ? light->next : 0;
	}
}
