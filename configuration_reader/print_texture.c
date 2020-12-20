/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:35:41 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/03 16:35:17 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	print_texture_map(t_map *map)
{
	printf("----->  width       =   %f\n", map->width);
	printf("----->  height      =   %f\n", map->height);
	printf("----->  u_scale     =   %f\n", map->u_scale);
	printf("----->  v_scale     =   %f\n", map->v_scale);
	printf("----->  bpp         =   %d\n", map->bpp);
	printf("----->  line_size   =   %d\n", map->line_size);
}

void	print_texture(t_texture *texture)
{
	if (texture->type[0] == CHECKERBOARD || texture->type[0] == RGB)
	{
		printf("rgb1 : ");
		print_rgb(texture->rgb1);
		if (texture->type[0] == CHECKERBOARD)
		{
			printf("rgb2 : ");
			print_rgb(texture->rgb2);
			printf("grid length = %f\n", texture->grid_len);
		}
	}
	else if (texture->type[0] == UV_MAP)
		print_texture_map(&(texture->uv_map));
	if (texture->type[1] == BUMP_MAP)
		print_texture_map(&(texture->bump_map));
}
