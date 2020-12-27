/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pyramid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 21:43:55 by youness           #+#    #+#             */
/*   Updated: 2020/12/27 17:07:19 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	update_faces_texture(t_texture *texture)
{
	texture->uv_map.u_scale = texture->width / texture->uv_map.width;
	texture->uv_map.v_scale = texture->height / texture->uv_map.height;
	texture->bump_map.u_scale = texture->width / texture->bump_map.width;
	texture->bump_map.v_scale = texture->height / texture->bump_map.height;
}

static void	update_pyramid_faces(t_pyramid *pyramid, int index)
{
	pyramid->faces[index]->parent = pyramid;
	pyramid->faces[index]->texture = pyramid->texture;
	if (pyramid->texture.type[0] == CHECKERBOARD)
	{
		if (index % 2)
		{
			pyramid->faces[index]->texture.rgb1 = pyramid->texture.rgb2;
			pyramid->faces[index]->texture.rgb2 = pyramid->texture.rgb1;
		}
		else
		{
			pyramid->faces[index]->texture.rgb1 = pyramid->texture.rgb1;
			pyramid->faces[index]->texture.rgb2 = pyramid->texture.rgb2;
		}
	}
}

int			build_pyramid(t_pyramid *pyramid, void **entities)
{
	int	i;

	pyramid->base->parent = pyramid;
	pyramid->base->parent_type = PYRAMID;
	pyramid->base->texture = pyramid->texture;
	i = -1;
	while (++i < 4)
	{
		if (!(pyramid->faces[i] = malloc(sizeof(t_triangle))))
			return (EMA);
		ft_lst_add_head(entities + TRIANGLE, pyramid->faces[i], TRIANGLE);
		update_pyramid_faces(pyramid, i);
	}
	build_pyramid_faces(pyramid, pyramid->base->radius, \
			pyramid->base->position);
	while (i--)
	{
		prepare_triangle_mapping(pyramid->faces[i]);
		update_faces_texture(&(pyramid->faces[i]->texture));
	}
	return (0);
}
