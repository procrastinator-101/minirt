/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:39:23 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/29 11:14:12 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

int	get_plane(char *line, void **entities)
{
	int		start;
	t_plane	*plane;

	if (!(plane = malloc(sizeof(t_plane))))
		return (-EMAF);
	ft_lst_add_head(entities + PLANE, plane, PLANE);
	start = update_start(line, 2);
	if (start == -1)
		return (-PLANE);
	start = fetch_point_3d(line, &(plane->position), start);
	start = update_start(line, start);
	if (start == -1)
		return (-PLANE);
	start = fetch_vector_3d(line, &(plane->basis.w), start);
	start = update_start(line, start);
	if (start == -1)
		return (-PLANE);
	plane->texture.width = PLANE_TILTING_SIZE;
	plane->texture.height = PLANE_TILTING_SIZE;
	get_base_3d(&(plane->basis.w), &(plane->basis.v), &(plane->basis.u));
	initialise_map_dimension(&(plane->texture));
	return (get_texture(line + start, &(plane->texture), entities[DISPLAY], \
		PLANE));
}
