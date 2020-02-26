/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_vector_3d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:47:28 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 14:47:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int	fetch_vector_3d(char *line, t_vector_3d *vector, int start)
{
	int	holder;

	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	vectorx = ft_atod_length(line + start, &holder);
	if (vectorx < -1.0 || vectorx > 1.0)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	vectory = ft_atod_length(line + start, &holder);
	if (vectory < -1.0 || vectory > 1.0)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43 && line[start] != 45)
		return (-1);
	vectorz = ft_atod_length(line + start, &holder);
	if (vectorz < -1.0 || vectorz > 1.0)
		return (-1);
	return (start + holder);
}
