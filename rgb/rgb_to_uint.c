/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:55:18 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/31 19:16:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

unsigned	rgb_to_uint(t_rgb rgb)
{
	unsigned	red;
	unsigned	green;
	unsigned	blue;
	unsigned	color;

	red = rgb.red > 1.0 ? 255 : rgb.red * 255.0;
	green = rgb.green > 1.0 ? 255 : rgb.green * 255.0;
	blue = rgb.blue > 1.0 ? 255 : rgb.blue * 255.0;
	color = (red << 16) + (green << 8) + blue;
	return (color);
}
