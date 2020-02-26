/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:11:52 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 14:29:20 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int		get_triangle(char *line, void **entities)
{
	int			start;
	t_triangle	triangle;

	if (!(triangle = malloc(sizeof(t_triangle))))
		return (0);
	ft_lstadd_head(&(entities[TRIANGLE]), triangle, TRIANGLE);
	start = update_start(line, 2);
	if (start == -1)
		return (0);
	start = fetch_point_3d(line, &(triangle->first_point), start);
	start = update_start(line, start);
	if (start == -1)
		return (0);
	start = fetch_point_3d(line, &(triangle->second_point), start);
	start = update_start(line, start);
	if (start == -1)
		return (0);
	start = fetch_point_3d(line, &(triangle->third_point), start);
	start = update_start(line, start);
	if (start == -1)
		return (0);
	if (fetch_rgb(line, &(triangle->rgb), start) == -1)
		return (0);
	return (1);
}
