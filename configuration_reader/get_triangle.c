/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:11:52 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/29 11:14:41 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int			get_triangle(char *line, void **entities)
{
	int			start;
	t_triangle	*triangle;

	if (!(triangle = malloc(sizeof(t_triangle))))
		return (-EMAF);
	ft_lst_add_head(entities + TRIANGLE, triangle, TRIANGLE);
	if ((start = update_start(line, 2)) == -1)
		return (-TRIANGLE);
	start = fetch_point_3d(line, &(triangle->p1), start);
	if ((start = update_start(line, start)) == -1)
		return (-TRIANGLE);
	start = fetch_point_3d(line, &(triangle->p2), start);
	if ((start = update_start(line, start)) == -1)
		return (-TRIANGLE);
	start = fetch_point_3d(line, &(triangle->p3), start);
	if ((start = update_start(line, start)) == -1)
		return (-TRIANGLE);
	triangle->parent = 0;
	prepare_triangle_mapping(triangle);
	initialise_map_dimension(&(triangle->texture));
	return (get_texture(line + start, &(triangle->texture), entities[DISPLAY], \
		TRIANGLE));
}
