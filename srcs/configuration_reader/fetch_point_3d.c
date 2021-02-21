/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_point_3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:19:01 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/19 12:04:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

int	fetch_point_3d(char *line, t_coord_3d *point, int start)
{
	int holder;

	if (!ft_isnumber(line + start))
		return (-1);
	point->x = ft_atod_length(line + start, &holder);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isnumber(line + start))
		return (-1);
	point->y = ft_atod_length(line + start, &holder);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isnumber(line + start))
		return (-1);
	point->z = ft_atod_length(line + start, &holder);
	return (start + holder);
}
