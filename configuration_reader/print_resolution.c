/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:24:45 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 20:19:01 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_resolution(void **entities)
{
	t_resolution	*resolution;

	resolution = entities[RESOLUTION];
	if (!resolution)
		return ;
	printf("\n\n===========	RESOLUTION	===========\n");
	printf("width = %d\n", resolution->width);
	printf("height = %d\n", resolution->height);
}
