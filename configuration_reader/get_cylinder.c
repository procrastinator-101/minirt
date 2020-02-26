/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:13:53 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 14:11:26 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	fill_cylindre_point(char *line, t_cylindre cylindre, int start)
{
	int holder;

	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	cylindre->cylindre_point.x = ft_atod_length(line + start, &holder);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	cylindre->cylindre_point.y = ft_atod_length(line + start, &holder);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	cylindre->cylindre_point.z = ft_atod_length(line + start, &holder);
	return (start + holder);
}

static int	fill_orientation_vec(char *line, t_cylindre cylindre, int start)
{
	int	holder;

	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	cylindre->orientation_vec.x = ft_atod_length(line + start, &holder);
	if (cylindre->orientation_vec.x < -1.0 || cylindre->orientation_vec.x > 1.0)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	cylindre->orientation_vec.y = ft_atod_length(line + start, &holder);
	if (cylindre->orientation_vec.y < -1.0 || cylindre->orientation_vec.y > 1.0)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	cylindre->orientation_vec.z = ft_atod_length(line + start, &holder);
	if (cylindre->orientation_vec.z < -1.0 || cylindre->orientation_vec.z > 1.0)
		return (-1);
	return (start + holder);
}

static int	fill_dimension(char *line, t_cylindre cylindre, int start)
{
	int	holder;

	if (!ft_isdigit(line[start]) && line[start] != 43)
		return (-1);
	cylindre->diameter = ft_atod_length(line + start, &holder);
	start = update_start(line, start + holder);
	if (start == -1)
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43)
		return (-1);
	cylindre->height = ft_atod_length(line + start, &holder);
	return (start + holder);
}

static int	fill_rgb(char *line, t_cylindre cylindre, int start)
{
	int holder;

	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	cylindre->rgb.red = ft_atoi_length(line + start, &holder);
	if (cylindre->rgb.red < 0 || cylindre->rgb.red > 255)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	cylindre->rgb.green = ft_atoi_length(line + start, &holder);
	if (cylindre->rgb.green < 0 || cylindre->rgb.green > 255)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	cylindre->rgb.blue = ft_atoi_length(line + start, &holder);
	if (cylindre->rgb.blue < 0 || cylindre->rgb.blue > 255)
		return (-1);
	return (start + holder);
}

int			get_cylinder(char *line, void **entities)
{
	int			start;
	t_cylindre	cylindre;

	if (!(cylindre = malloc(sizeof(t_cylindre))))
		return (0);
	//ft_lstadd_head(&(entities[CYLINDER]), cylindre, CYLINDER);
	entities[CYLINDER] = cylindre;
	cylindre->next = 0;
	start = update_start(line, 2);
	if (start == -1)
		return (0);
	start = fill_cylindre_point(line, cylindre, start);
	start = update_start(line, start);
	if (start == -1)
		return (0);
	start = fill_orientation_vec(line, cylindre, start);
	start = update_start(line, start);
	if (start == -1)
		return (0);
	start = fill_rgb(line, cylindre, start);
	start = update_start(line, start);
	if (start == -1)
		return (0);
	if (fill_dimension(line, cylindre, start) == -1)
		return (0);
	return (1);
}
