/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:01:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 18:08:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int	rgb_to_int(t_rgb rgb, int endian)
{
	int				color;
	unsigned char 	*ptr;

	ptr = (unsigned char *)(&color);
	if (endian)
	{
		ptr[0] = 0;
		ptr[1] = rgb.red;
		ptr[2] = rgb.green;
		ptr[3] = rgb.blue;
	}
	else
	{
		ptr[0] = rgb.blue;
		ptr[1] = rgb.green;
		ptr[2] = rgb.red;
		ptr[3] = 0;
	}
	return (color);
}
