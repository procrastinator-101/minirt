/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:15:54 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 18:25:09 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_rgb(t_rgb rgb)
{
	printf("red = %d\n", rgb.red);
	printf("green = %d\n", rgb.green);
	printf("blue = %d\n", rgb.blue);
}
