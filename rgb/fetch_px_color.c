/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_px_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:03:51 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/31 17:05:01 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	fetch_pix_color(t_texture texture, t_display *display, double x, \
		double y)
{
	int			px;
	int			py;
	unsigned	color;

	px = floor(fabs(x) * texture.u_scale);
	py = floor(fabs(y) * texture.v_scale);
	if (x > 0)
		px *= 2;
	if (y < 0)
		py *= 2;
	color = *((unsigned int *)(texture.texture_map + py * display->line_size + px * display->bpp / 8));
	return (uint_to_rgb(color, display->server_endian));
}
