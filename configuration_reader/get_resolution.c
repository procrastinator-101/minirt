/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:24:09 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 15:02:06 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	get_resolution(char *line, void **entities)
{
	int				start;
	int				holder;
	t_resolution	*resolution;

	if (entities[RESOLUTION])
		return (-RESOLUTION);
	if (!(resolution = malloc(sizeof(t_resolution))))
		return (-RESOLUTION);
	entities[RESOLUTION] = (void *)resolution;
	start = find_next_arg(line, 2);
	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-RESOLUTION);
	resolution->width = ft_atoi_length(line + start, &holder);
	if (resolution->width < 1)
		return (-RESOLUTION);
	start = find_next_arg(line, start + holder);
	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-RESOLUTION);
	resolution->height = ft_atoi(line + start);
	if (resolution->height < 1)
		return (-RESOLUTION);
	return (RESOLUTION);
}
