/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:42:31 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/24 23:20:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	fill_camera_position(char *line, t_camera *camera, int start)
{
	int holder;

	camera->position.x = basic_atod(line + start, &holder);
	start += holder + 1;
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	camera->position.y = basic_atod(line + start, &holder);
	start += holder + 1;
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	camera->position.z = basic_atod(line + start, &holder);
	start += holder;
	return (start);
}

static int	fill_camera_orientation_vec(char *line, t_camera *camera, \
		int start)
{
	int	holder;

	camera->orientation_vec.x = basic_atod(line + start, &holder);
	start += holder + 1;
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	camera->orientation_vec.y = basic_atod(line + start, &holder);
	start += holder + 1;
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	camera->orientation_vec.z = basic_atod(line + start, &holder);
	start += holder;
	return (start);
}

int			get_camera(char *line, void **entities)
{
	int			start;
	int			holder;
	t_camera	*camera;

	if (!(camera = malloc(sizeof(t_camera))))
		return (0);
	entities[2] = (void *)camera;
	start = find_next_arg(line, 2);
	start = fill_camera_position(line, camera, start);
	if (start == -1)
		return (0);
	holder = find_next_arg(line, start);
	if (holder == start)
		return (0);
	start = fill_camera_orientation_vec(line, camera, holder);
	if (start == -1)
		return (0);
	holder = find_next_arg(line, start);
	if (holder == start)
		return (0);
	camera->fov = basic_atod(line + start, &holder);
	return (1);
}
