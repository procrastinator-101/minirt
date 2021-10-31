/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bump_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:30:25 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/27 10:20:42 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int			adjust_pixel_coordinate(int c, int max_dim)
{
	if (c >= max_dim)
		c = max_dim - 1;
	else if (c < 0)
		c = 0;
	return (c);
}

static t_coord_3d	perturb_normal(t_map *bump_map, t_coord_3d n, int px, \
					int py)
{
	unsigned	*color;
	t_rgb		rgb;
	t_coord_3d	u;
	t_coord_3d	v;

	get_base_3d(&n, &v, &u);
	color = (unsigned *)(bump_map->img_addr + py * bump_map->line_size + \
			(px * bump_map->bpp) / 8);
	rgb = uint_to_rgb(*color);
	u = scalar_product(u, 2 * rgb.red - 1);
	v = scalar_product(v, 2 * rgb.green - 1);
	n = scalar_product(n, 2 * rgb.blue - 1);
	n = coord_3d_add(u, coord_3d_add(v, n));
	normalise_3d_vec(&n);
	return (n);
}

t_coord_3d			get_bump_normal(t_map *bump_map, t_3d_basis *basis, \
					t_coord_3d n, t_coord_3d v)
{
	int		px;
	int		py;
	double	x;
	double	y;

	x = dot_product(v, basis->u);
	y = dot_product(v, basis->v);
	px = ((int)bump_map->width) / 2 + (int)floor(x / bump_map->u_scale);
	py = ((int)bump_map->height) / 2 - (int)floor(y / bump_map->v_scale);
	px = adjust_pixel_coordinate(px, (int)bump_map->width);
	py = adjust_pixel_coordinate(py, (int)bump_map->height);
	return (perturb_normal(bump_map, n, px, py));
}
