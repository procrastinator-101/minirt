/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:42:31 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/24 21:44:12 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	read_double(char *line, int start, double *arg)
{
	int	sign;
	int	radix;
	int holder;

	sign = line[start] == '-';
	start += sign;
	if (!ft_isdigit(line[start + sign]))
		return (-1);
	holder = ft_atoi(line + start);
	start += holder ? (int)log10(holder) + 1 : 1;
	if (line[start] == '.')
	{
		if (!ft_isdigit(line[++start]))
			return (-1);
		*arg = ft_atoi(line + start);
		radix = *arg != 0.0 ? (int)log10(*arg) + 1 : 1;
		*arg /= pow(10.0, radix);
		start += radix;
	}
	*arg += holder;
	*arg = sign ? -(*arg) : *arg;
	return (start);
}

static int	fill_camera_position(char *line, t_camera *camera, int start)
{
	start = read_double(line, start, &(camera->position.x));
	if (start == -1)
		return (-1);
	start = find_next_arg(line, start) + 1;
	start = read_double(line, start, &(camera->position.y));
	if (start == -1)
		return (-1);
	start = find_next_arg(line, start) + 1;
	start = read_double(line, start, &(camera->position.z));
	return (start);
}

int			get_camera(char *line, void **entities)
{
	int			start;
	t_camera	*camera;

	if (!(camera = malloc(sizeof(t_camera))))
		return (0);
	entities[2] = (void *)camera;
	start = find_next_arg(line, 2);
	start = fill_camera_position(line, camera, start);
	if (start == -1)
		return (0);
	return (1);
}
