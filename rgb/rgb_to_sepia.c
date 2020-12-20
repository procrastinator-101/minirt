/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_sepia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 20:27:40 by youness           #+#    #+#             */
/*   Updated: 2020/10/16 19:45:13 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	rgb_to_sepia(t_rgb rgb)
{
	rgb = adjust_rgb(rgb);
	rgb.red = 0.393 * rgb.red + 0.769 * rgb.green + 0.189 * rgb.blue;
	rgb.green = 0.349 * rgb.red + 0.686 * rgb.green + 0.168 * rgb.blue;
	rgb.blue = 0.272 * rgb.red + 0.534 * rgb.green + 0.131 * rgb.blue;
	return (rgb);
}
