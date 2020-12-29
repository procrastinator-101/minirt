/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pyramid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 20:57:18 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/29 11:18:19 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

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
	get_base_3d(&(pyramid->base->basis.w), &(pyramid->base->basis.v), \
		&(pyramid->base->basis.u));
	start = update_start(line, start);
	if (start == -1)
		return (-1);
	start = get_radius(line, &(pyramid->base->radius), start);
	if (start == -1)
		return (-1);
	return (start);
}

int			get_pyramid(char *line, void **entities)
{
	int			start;
	t_coord_3d	v;
	t_pyramid	*pyramid;

	if (!(pyramid = malloc(sizeof(t_pyramid))))
		return (-EMAF);
	ft_lst_add_head(entities + PYRAMID, pyramid, PYRAMID);
	if (!(pyramid->base = malloc(sizeof(t_square))))
		return (-EMAF);
	ft_lst_add_head(entities + SQUARE, pyramid->base, SQUARE);
	start = get_pyramid_base(line, pyramid);
	if (start == -1)
		return (-PYRAMID);
	start = fetch_point_3d(line, &(pyramid->apex), start);
	start = update_start(line, start);
	if (start == -1)
		return (-PYRAMID);
	v = coord_3d_minus(pyramid->apex, pyramid->base->position);
	pyramid->texture.width = pyramid->base->radius * 2.0;
	pyramid->texture.height = pyramid->texture.width;
	initialise_map_dimension(&(pyramid->texture));
	return (get_texture(line + start, &(pyramid->texture), entities[DISPLAY], \
		PYRAMID));
}
