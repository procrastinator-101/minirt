/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:42:31 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 16:42:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static int	fill_fov(char *line, t_camera *camera, int start)
{
	if (!ft_isdigit(line[start]) && line[start] != 43)
		return (-1);
	camera->fov = ft_atoi(line + start);
	if (camera->fov < 0 || camera->fov > 180)
		return (-1);
	return (1);
}

int			get_camera(char *line, void **entities)
{
	int			start;
	t_camera	*camera;

	if (!(camera = malloc(sizeof(t_camera))))
		return (-CAMERA);
	ft_lstadd_head(&(entities[CAMERA]), camera, CAMERA);
	camera->next = 0;
	start = find_next_arg(line, 2);
	start = fetch_point_3d(line, &(camera->position), start);
	start = update_start(line, start);
	if (start == -1)
		return (-CAMERA);
	start = fetch_vector_3d(line, &(camera->orientation_vec), start);
	start = update_start(line, start);
	if (start == -1)
		return (-CAMERA);
	if (fill_fov(line, camera, start) == -1)
		return (-CAMERA);
	return (CAMERA);
}
