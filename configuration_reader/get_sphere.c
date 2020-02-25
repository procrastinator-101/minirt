/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:51:13 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/25 18:31:13 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	fill_point_light(char *line, t_sphere sphere, int start)
{
	int holder;

	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	sphere->sphere_point.x = basic_atod(line + start, &holder);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	sphere->sphere_point.y = basic_atod(line + start, &holder);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	sphere->sphere_point.z = basic_atod(line + start, &holder);
	return (start + holder);
}

static int	fill_diameter(char *line, t_sphere sphere, int start)
{
	if (!ft_isdigit(line[start]) && line[start] != 43)
		return (-1);
	sphere->diameter = ft_atod_length(line + start, &start);
	return (start);
}

static int	fill_rgb(char *line, t_sphere sphere, int start)
{
	int holder;

	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	sphere->rgb.red = ft_atoi_length(line + start, &holder);
	if (sphere->rgb.red < 0 || sphere->rgb.red > 255)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	sphere->rgb.green = ft_atoi_length(line + start, &holder);
	if (sphere->rgb.green < 0 || sphere->rgb.green > 255)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	sphere->rgb.blue = ft_atoi_length(line + start, &holder);
	if (sphere->rgb.blue < 0 || sphere->rgb.blue > 255)
		return (-1);
	return (start + holder);
}

static int	update_start(char *line, int start)
{
	int new_start;

	if (start == -1)
		return (-1);
	new_start = find_next_arg(line, start);
	if (new_start == start)
		return (-1);
	return (new_start);
}

int			get_sphere(char *line, void **entities)
{
	int			start;
	int			holder;
	t_sphere	sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		return (0);
	//ft_lstadd_head(&(entities[SPHERE]), sphere, SPHERE);
	entities[SPHERE] = sphere;
	sphere->next = 0;
	start = update_start(line, 2);
	if (start == -1)
		return (0);
	start = fill_point_light(line, sphere, start);
	start = update_start(line, start);
	if (start == -1)
		return (0);
	start = fill_diameter(line, sphere, holder);
	start = update_start(line, start);
	if (start == -1)
		return (0);
	if (fill_rgb(line, sphere, start) == -1)
		return (0);
	return (1);
}
