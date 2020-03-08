/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:51:13 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/08 12:03:27 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static int	fill_radius(char *line, t_sphere *sphere, int start)
{
	int holder;

	if (!ft_isdigit(line[start]) && line[start] != 43)
		return (-1);
	sphere->radius = ft_atod_length(line + start, &holder) / 2;
	return (start + holder);
}

int			get_sphere(char *line, void **entities)
{
	int			start;
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		return (-SPHERE);
	ft_lstadd_head(&(entities[SPHERE]), sphere, SPHERE);
	sphere->next = entities[SPHERE];
	start = update_start(line, 2);
	if (start == -1)
		return (-SPHERE);
	start = fetch_point_3d(line, &(sphere->center), start);
	start = update_start(line, start);
	if (start == -1)
		return (-SPHERE);
	start = fill_radius(line, sphere, start);
	start = update_start(line, start);
	if (start == -1)
		return (-SPHERE);
	if (fetch_rgb(line, &(sphere->rgb), start) == -1)
		return (-SPHERE);
	return (SPHERE);
}
