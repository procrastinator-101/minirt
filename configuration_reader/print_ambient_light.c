/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:01:02 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 18:04:15 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_ambient_light(void **entities)
{
	t_ambient	*ambient;

	ambient = entities[AMBIENT];
	if (!ambient)
		return ;
	printf("ratio = %f\n", ambient->ratio);
	printf_rgb(ambient->rgb);
}
