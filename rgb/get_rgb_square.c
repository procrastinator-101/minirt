/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:39:58 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/04 12:10:16 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	get_rgb_square(t_square *square, t_coord_3d p)
{
	int		rgb_nb;
	double	x;
	double	y;

	if (square->texture.type[0] == RGB)
		return (square->texture.rgb1);
	p = coord_3d_minus(p, square->position);
	x = dot_product(p, square->basis.u);
	y = dot_product(p, square->basis.v);
	if (square->texture.type[0] == CHECKERBOARD)
	{
		rgb_nb = get_rgb_nb(x, y, square->texture.grid_len);
		return (rgb_nb ? square->texture.rgb2 : square->texture.rgb1);
	}
	if (square->texture.type[0] == UV_MAP)
		return (get_map_pix_color(&(square->texture.uv_map), x, y));
	return (get_black_rgb());
}
