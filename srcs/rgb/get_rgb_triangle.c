/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_triangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:02:40 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/06 20:04:33 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	get_rgb_triangle(t_triangle *triangle, t_coord_3d p)
{
	int			rgb_nb;
	double		x;
	double		y;

	if (triangle->texture.type[0] == RGB)
		return (triangle->texture.rgb1);
	p = coord_3d_sub(p, triangle->c);
	x = dot_product(p, triangle->basis.u);
	y = dot_product(p, triangle->basis.v);
	if (triangle->texture.type[0] == CHECKERBOARD)
	{
		rgb_nb = get_rgb_nb(x, y, triangle->texture.grid_len);
		return (rgb_nb ? triangle->texture.rgb2 : triangle->texture.rgb1);
	}
	if (triangle->texture.type[0] == UV_MAP)
		return (get_map_pix_color(&(triangle->texture.uv_map), x, y));
	return (get_black_rgb());
}
