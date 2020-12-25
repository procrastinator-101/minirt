/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:28:18 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/25 10:05:13 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static double	tilt_point_coordinates(double c)
{
	double	tmp;

	tmp = c;
	c = fabs(c);
	if (c > PLANE_TILTING_SIZE / 2.0)
	{
		c += PLANE_TILTING_SIZE / 2.0;
		c = fmod(c, PLANE_TILTING_SIZE);
		c -= PLANE_TILTING_SIZE / 2.0;
	}
	return (tmp < 0 ? -c : c);
}

t_rgb			get_rgb_plane(t_plane *plane, t_coord_3d p)
{
	int			rgb_nb;
	double		x;
	double		y;

	if (plane->texture.type[0] == RGB)
		return (plane->texture.rgb1);
	p = coord_3d_minus(p, plane->position);
	x = dot_product(p, plane->basis.u);
	y = dot_product(p, plane->basis.v);
	if (plane->texture.type[0] == CHECKERBOARD)
	{
		rgb_nb = get_rgb_nb(x, y, plane->texture.grid_len);
		return (rgb_nb ? plane->texture.rgb2 : plane->texture.rgb1);
	}
	x = tilt_point_coordinates(x);
	y = tilt_point_coordinates(y);
	if (plane->texture.type[0] == UV_MAP)
		return (get_map_pix_color(&(plane->texture.uv_map), x, y));
	return (get_black_rgb());
}
