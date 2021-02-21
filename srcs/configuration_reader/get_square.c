/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:13:26 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/22 15:04:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

int	get_square(char *line, void **entities)
{
	int			start;
	t_square	*square;

	if (!(square = malloc(sizeof(t_square))))
		return (-EMAF);
	ft_lst_add_head(entities + SQUARE, square, SQUARE);
	square->parent = 0;
	square->texture.uv_map.img_ptr = 0;
	square->texture.bump_map.img_ptr = 0;
	if ((start = update_start(line, 2)) == -1)
		return (-SQUARE);
	start = fetch_point_3d(line, &(square->position), start);
	if ((start = update_start(line, start)) == -1)
		return (-SQUARE);
	start = fetch_vector_3d(line, &(square->basis.w), start);
	if ((start = update_start(line, start)) == -1)
		return (-SQUARE);
	if ((start = get_radius(line, &(square->radius), start)) == -1)
		return (-SQUARE);
	get_base_3d(&(square->basis.w), &(square->basis.v), &(square->basis.u));
	square->texture.width = square->radius * 2.0;
	square->texture.height = square->texture.width;
	initialise_map_dimension(&(square->texture));
	return (get_texture(line + start, &(square->texture), entities[DISPLAY], \
		SQUARE));
}
