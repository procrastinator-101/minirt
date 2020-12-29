/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:42:31 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/29 11:12:49 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static int	fill_fov(char *line, t_camera *camera, int start)
{
	int	holder;

	if (!ft_isdigit(line[start]) && line[start] != 43)
		return (-1);
	camera->fov = ft_atoi_length(line + start, &holder);
	if (camera->fov < 0 || camera->fov > 180)
		return (-1);
	return (start + holder);
}

int			get_camera(char *line, void **entities)
{
	int			start;
	t_camera	*camera;

	if (!(camera = malloc(sizeof(t_camera))))
		return (-EMAF);
	ft_dclst_add_head(entities + CAMERA, camera, CAMERA);
	camera->next = entities[CAMERA];
	start = update_start(line, 1);
	if (start == -1)
		return (-CAMERA);
	start = fetch_point_3d(line, &(camera->position), start);
	start = update_start(line, start);
	if (start == -1)
		return (-CAMERA);
	start = fetch_vector_3d(line, &(camera->screen.w), start);
	start = update_start(line, start);
	if (start == -1)
		return (-CAMERA);
	start = fill_fov(line, camera, start);
	return (check_end_entity_info(line, start, CAMERA));
}
