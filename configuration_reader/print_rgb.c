/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:15:54 by yarroubi          #+#    #+#             */
/*   Updated: 2020/06/24 19:39:53 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_rgb(t_rgb rgb)
{
	printf("red   = %f\n", rgb.red);
	printf("green = %f\n", rgb.green);
	printf("blue  = %f\n", rgb.blue);
}
