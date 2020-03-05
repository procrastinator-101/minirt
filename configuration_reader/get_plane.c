/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:39:23 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/05 15:31:06 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int			get_plane(char *line, void **entities)
{
	int		start;
	t_plane	*plane;

	if (!(plane = malloc(sizeof(t_plane))))
		return (-PLANE);
	ft_lstadd_head(&(entities[PLANE]), plane, PLANE);
	plane->next = entities[PLANE];
	start = update_start(line, 2);
	if (start == -1)
		return (-PLANE);
	start = fetch_point_3d(line, &(plane->plane_point), start);
	start = update_start(line, start);
	if (start == -1)
		return (-PLANE);
	start = fetch_vector_3d(line, &(plane->orientation_vec), start);
	start = update_start(line, start);
	if (start == -1)
		return (-PLANE);
	if (fetch_rgb(line, &(plane->rgb), start) == -1)
		return (-PLANE);
	return (PLANE);
}
