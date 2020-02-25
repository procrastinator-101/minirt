/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:39:23 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/25 19:05:16 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	fill_plane_point(char *line, t_plane *plane, int start)
{
	int holder;

	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	plane->plane_point.x = ft_atod_length(line + start, &holder);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	plane->plane_point.y = ft_atod_length(line + start, &holder);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	plane->plane_point.z = ft_atod_length(line + start, &holder);
	return (start + holder);
}

static int	fill_plane_orientation_vec(char *line, t_plane *plane, int start)
{
	int	holder;

	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	plane->orientation_vec.x = ft_atod_length(line + start, &holder);
	if (plane->orientation_vec.x < -1.0 || plane->orientation_vec.x > 1.0)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	plane->orientation_vec.y = ft_atod_length(line + start, &holder);
	if (plane->orientation_vec.y < -1.0 || plane->orientation_vec.y > 1.0)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	plane->orientation_vec.z = ft_atod_length(line + start, &holder);
	if (plane->orientation_vec.z < -1.0 || plane->orientation_vec.z > 1.0)
		return (-1);
	return (start + holder);
}

static int	fill_rgb(char *line, t_plane *plane, int start)
{
	int holder;

	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	plane->rgb.red = ft_atoi_length(line + start, &holder);
	if (plane->rgb.red < 0 || plane->rgb.red > 255)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	plane->rgb.green = ft_atoi_length(line + start, &holder);
	if (plane->rgb.green < 0 || plane->rgb.green > 255)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	plane->rgb.blue = ft_atoi_length(line + start, &holder);
	if (plane->rgb.blue < 0 || plane->rgb.blue > 255)
		return (-1);
	return (start + holder);
}

int			get_plane(char *line, void **entities)
{
	int		start;
	int		holder;
	t_plane	plane;

	if (!(plane = malloc(sizeof(t_plane))))
		return (0);
	//ft_lstadd_head(&(entities[PLANE]), plane, PLANE);
	entities[PLANE] = plane;
	plane->next = 0;

}
