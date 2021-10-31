/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:28:18 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/31 14:11:14 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	get_rgb_plane(t_plane *plane, t_coord_3d p)
{
	int			rgb_nb;
	double		x;
	double		y;

	if (plane->texture.type[0] == RGB)
		return (plane->texture.rgb1);
	p = coord_3d_sub(p, plane->position);
	x = dot_product(p, plane->basis.u);
	y = dot_product(p, plane->basis.v);
	if (plane->texture.type[0] == CHECKERBOARD)
	{
		rgb_nb = get_rgb_nb(x, y, plane->texture.grid_len);
		return (rgb_nb ? plane->texture.rgb2 : plane->texture.rgb1);
	}
	x = tilt(x, PLANE_TILTING_SIZE);
	y = tilt(y, PLANE_TILTING_SIZE);
	if (plane->texture.type[0] == UV_MAP)
		return (get_map_pix_color(&(plane->texture.uv_map), x, y));
	return (get_black_rgb());
}
