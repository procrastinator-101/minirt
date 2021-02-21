/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_vector_3d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:47:28 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/19 12:06:30 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

int	fetch_vector_3d(char *line, t_coord_3d *vector, int start)
{
	int	holder;

	if (!ft_isnumber(line + start))
		return (-1);
	vector->x = ft_atod_length(line + start, &holder);
	if (vector->x < -1.0 || vector->x > 1.0)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isnumber(line + start))
		return (-1);
	vector->y = ft_atod_length(line + start, &holder);
	if (vector->y < -1.0 || vector->y > 1.0)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isnumber(line + start))
		return (-1);
	vector->z = ft_atod_length(line + start, &holder);
	if (vector->z < -1.0 || vector->z > 1.0)
		return (-1);
	normalise_3d_vec(vector);
	return (start + holder);
}
