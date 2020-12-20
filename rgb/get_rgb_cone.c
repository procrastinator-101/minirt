/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:42:03 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/04 12:09:53 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	get_rgb_cone(t_cone *cone, t_coord_3d p)
{
	int			rgb_nb;
	double		x;
	double		y;

	if (cone->texture.type[0] == RGB)
		return (cone->texture.rgb1);
	p = coord_3d_minus(p, cone->vertex);
	x = dot_product(p, cone->basis.u);
	y = dot_product(p, cone->basis.v);
	if (cone->texture.type[0] == CHECKERBOARD)
	{
		rgb_nb = get_rgb_nb(x, y, cone->texture.grid_len);
		return (rgb_nb ? cone->texture.rgb2 : cone->texture.rgb1);
	}
	if (cone->texture.type[0] == UV_MAP)
		return (get_map_pix_color(&(cone->texture.uv_map), x, y));
	return (get_black_rgb());
}
