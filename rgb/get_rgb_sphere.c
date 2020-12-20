/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:37:22 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/04 12:08:10 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	get_rgb_sphere(t_sphere *sphere, t_coord_3d p)
{
	int		rgb_nb;
	double	x;
	double	y;

	if (sphere->texture.type[0] == RGB)
		return (sphere->texture.rgb1);
	p = coord_3d_minus(p, sphere->center);
	x = dot_product(p, sphere->basis.u);
	y = dot_product(p, sphere->basis.v);
	if (sphere->texture.type[0] == CHECKERBOARD)
	{
		rgb_nb = get_rgb_nb(x, y, sphere->texture.grid_len);
		return (rgb_nb ? sphere->texture.rgb2 : sphere->texture.rgb1);
	}
	if (sphere->texture.type[0] == UV_MAP)
		return (get_map_pix_color(&(sphere->texture.uv_map), x, y));
	return (get_black_rgb());
}
