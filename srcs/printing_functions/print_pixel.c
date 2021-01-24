/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:06:05 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 12:52:45 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_pixel(t_pixel pixel)
{
	printf("----------	pixel	----------");
	printf("width = %f\n", pixel.width);
	printf("height = %f\n", pixel.height);
}
