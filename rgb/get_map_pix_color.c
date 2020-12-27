/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_pix_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:38:46 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/27 10:32:10 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static int		adjust_pixel_coordinate(int c, int max_dim)
{
	if (c >= max_dim)
		c = max_dim - 1;
	else if (c < 0)
		c = 0;
	return (c);
}

static	t_rgb	linearly_interpolate(t_map *map, int px, int py)
{
	int			i;
	int			j;
	unsigned	*ptr;
	t_rgb		rgb;

	i = -1;
	while (++i < 2)
	{
		py += i;
		py = adjust_pixel_coordinate(py, (int)map->height);
		j = -1;
		while (++j < 2)
		{
			px += j;
			px = adjust_pixel_coordinate(px, (int)map->width);
			ptr = (unsigned *)(map->img_addr + py * map->line_size + \
				(px * map->bpp) / 8);
			rgb = rgb_sum(rgb, uint_to_rgb(*ptr));
		}
	}
	return (rgb_mul_double(rgb, 1 / 4.0));
}

t_rgb			get_map_pix_color(t_map *map, double x, double y)
{
	int			px;
	int			py;
	unsigned	*ptr;

	px = ((int)map->width) / 2 + (int)floor(x / map->u_scale);
	py = ((int)map->height) / 2 - (int)floor(y / map->v_scale);
	px = adjust_pixel_coordinate(px, (int)map->width);
	py = adjust_pixel_coordinate(py, (int)map->height);
	ptr = (unsigned *)(map->img_addr + py * map->line_size + \
		(px * map->bpp) / 8);
	if (LINEAR_INTERPOLATION)
		return (linearly_interpolate(map, px, py));
	return (uint_to_rgb(*ptr));
}
