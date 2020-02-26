/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:39:23 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 14:46:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int			get_plane(char *line, void **entities)
{
	int		start;
	t_plane	plane;

	if (!(plane = malloc(sizeof(t_plane))))
		return (0);
	ft_lstadd_head(&(entities[PLANE]), plane, PLANE);
	//entities[PLANE] = plane;
	plane->next = 0;
	start = update_start(line, 2);
	if (start == -1)
		return (0);
	start = fetch_point_3d(line, &(plane->plane_point), start);
	start = update_start(line, start);
	if (start == -1)
		return (0);
	start = fetch_vector_3d(line, &(plane->orientation_vec), start);
	start = update_start(line, start);
	if (start == -1)
		return (0);
	if (fetch_rgb(line, &(plane->rgb), start) == -1)
		return (0);
	return (1);
}
