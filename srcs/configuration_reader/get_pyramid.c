/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pyramid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 20:57:18 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/19 09:23:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

static int	get_pyramid_base(char *line, t_pyramid *pyramid)
{
	int	start;

	start = update_start(line, 2);
	if (start == -1)
		return (-1);
	start = fetch_point_3d(line, &(pyramid->base->position), start);
	start = update_start(line, start);
	if (start == -1)
		return (-1);
	start = fetch_vector_3d(line, &(pyramid->base->basis.w), start);
	start = update_start(line, start);
	if (start == -1)
		return (-1);
	get_base_3d(&(pyramid->base->basis.w), &(pyramid->base->basis.v), \
		&(pyramid->base->basis.u));
	start = get_radius(line, &(pyramid->base->radius), start);
	return (start);
}

int			get_pyramid(char *line, void **entities)
{
	int			start;
	t_pyramid	*pyramid;

	if (!(pyramid = malloc(sizeof(t_pyramid))))
		return (-EMAF);
	ft_lst_add_head(entities + PYRAMID, pyramid, PYRAMID);
	pyramid->texture.uv_map.img_ptr = 0;
	pyramid->texture.bump_map.img_ptr = 0;
	if (!(pyramid->base = malloc(sizeof(t_square))))
		return (-EMAF);
	ft_lst_add_head(entities + SQUARE, pyramid->base, SQUARE);
	pyramid->base->texture.uv_map.img_ptr = 0;
	pyramid->base->texture.bump_map.img_ptr = 0;
	start = get_pyramid_base(line, pyramid);
	if (start == -1)
		return (-PYRAMID);
	start = fetch_point_3d(line, &(pyramid->apex), start);
	if ((start = update_start(line, start)) == -1)
		return (-PYRAMID);
	pyramid->texture.width = pyramid->base->radius * 2.0;
	pyramid->texture.height = pyramid->texture.width;
	initialise_map_dimension(&(pyramid->texture));
	return (get_texture(line + start, &(pyramid->texture), entities[DISPLAY], \
		PYRAMID));
}
