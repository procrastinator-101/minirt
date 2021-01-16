/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:40:33 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/16 20:03:00 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	adjust_rgb(t_rgb rgb)
{
	rgb.red = rgb.red > 1.0 ? 1.0 : rgb.red;
	rgb.green = rgb.green > 1.0 ? 1.0 : rgb.green;
	rgb.blue = rgb.blue > 1.0 ? 1.0 : rgb.blue;
	return (rgb);
}
