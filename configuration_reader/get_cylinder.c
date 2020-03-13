/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:13:53 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/13 22:35:16 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static int	fill_dimension(char *line, t_cylinder *cylinder, int start)
{
	int	holder;

	if (!ft_isdigit(line[start]) && line[start] != 43)
		return (-1);
	cylinder->diameter = ft_atod_length(line + start, &holder);
	start = update_start(line, start + holder);
	if (start == -1)
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43)
		return (-1);
	cylinder->height = ft_atod_length(line + start, &holder);
	return (start + holder);
}

static void	get_u_vec(t_coord_3d v, t_coord_3d center)
{
	double		d;
	t_coord_3d	u;
	t_coord_3d	l;

	d = -dot_product(position, v);
	l = cross_product(u, v);
}

int			get_cylinder(char *line, void **entities)
{
	int			start;
	t_cylinder	*cylinder;

	if (!(cylinder = malloc(sizeof(t_cylinder))))
		return (-CYLINDER);
	ft_lstadd_head(&(entities[CYLINDER]), cylinder, CYLINDER);
	cylinder->next = entities[CYLINDER];
	start = update_start(line, 2);
	if (start == -1)
		return (-CYLINDER);
	start = fetch_point_3d(line, &(cylinder->position), start);
	start = update_start(line, start);
	if (start == -1)
		return (-CYLINDER);
	start = fetch_vector_3d(line, &(cylinder->v), start);
	start = update_start(line, start);
	if (start == -1)
		return (-CYLINDER);
	start = fetch_rgb(line, &(cylinder->rgb), start);
	start = update_start(line, start);
	if (start == -1)
		return (-CYLINDER);
	if (fill_dimension(line, cylinder, start) == -1)
		return (-CYLINDER);
	return (CYLINDER);
}
