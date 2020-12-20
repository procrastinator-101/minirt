/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:06:05 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/28 20:10:15 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_pixel(t_pixel pixel)
{
	printf("----------	pixel	----------");
	printf("width = %f\n", pixel.width);
	printf("height = %f\n", pixel.height);
	printf("basis {u,v} :\n");
	print_coord_3d(pixel.u);
	print_coord_3d(pixel.v);
}
