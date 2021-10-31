/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:41:15 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/04 12:10:43 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	get_rgb_cylinder(t_cylinder *cylinder, t_coord_3d p)
{
	int		rgb_nb;
	double	x;
	double	y;

	if (cylinder->texture.type[0] == RGB)
		return (cylinder->texture.rgb1);
	p = coord_3d_sub(p, cylinder->position);
	x = dot_product(p, cylinder->basis.u);
	y = dot_product(p, cylinder->basis.v);
	if (cylinder->texture.type[0] == CHECKERBOARD)
	{
		rgb_nb = get_rgb_nb(x, y, cylinder->texture.grid_len);
		return (rgb_nb ? cylinder->texture.rgb2 : cylinder->texture.rgb1);
	}
	if (cylinder->texture.type[0] == UV_MAP)
		return (get_map_pix_color(&(cylinder->texture.uv_map), x, y));
	return (get_black_rgb());
}
