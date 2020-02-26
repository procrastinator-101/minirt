/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:11:52 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 15:22:14 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int		get_triangle(char *line, void **entities)
{
	int			start;
	t_triangle	triangle;

	if (!(triangle = malloc(sizeof(t_triangle))))
		return (-TRIANGLE);
	ft_lstadd_head(&(entities[TRIANGLE]), triangle, TRIANGLE);
	start = update_start(line, 2);
	if (start == -1)
		return (-TRIANGLE);
	start = fetch_point_3d(line, &(triangle->first_point), start);
	start = update_start(line, start);
	if (start == -1)
		return (-TRIANGLE);
	start = fetch_point_3d(line, &(triangle->second_point), start);
	start = update_start(line, start);
	if (start == -1)
		return (-TRIANGLE);
	start = fetch_point_3d(line, &(triangle->third_point), start);
	start = update_start(line, start);
	if (start == -1)
		return (-TRIANGLE);
	if (fetch_rgb(line, &(triangle->rgb), start) == -1)
		return (-TRIANGLE);
	return (TRIANGLE);
}
