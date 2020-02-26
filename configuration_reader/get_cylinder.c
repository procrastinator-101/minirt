/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:13:53 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 15:45:04 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

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

int			get_cylinder(char *line, void **entities)
{
	int			start;
	t_cylindre	cylindre;

	if (!(cylindre = malloc(sizeof(t_cylindre))))
		return (-CYLINDER);
	ft_lstadd_head(&(entities[CYLINDER]), cylindre, CYLINDER);
	cylindre->next = 0;
	start = update_start(line, 2);
	if (start == -1)
		return (-CYLINDER);
	start = fetch_point_3d(line, &(cylindre->cylindre_point), start);
	start = update_start(line, start);
	if (start == -1)
		return (-CYLINDER);
	start = fetch_vector_3d(line, &(cylindre->orientation_vec), start);
	start = update_start(line, start);
	if (start == -1)
		return (-CYLINDER);
	start = fetch_rgb(line, &(cylindre->rgb), start);
	start = update_start(line, start);
	if (start == -1)
		return (-CYLINDER);
	if (fill_dimension(line, cylindre, start) == -1)
		return (-CYLINDER);
	return (CYLINDER);
}
