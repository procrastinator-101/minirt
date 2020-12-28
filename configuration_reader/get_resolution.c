/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:24:09 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/28 17:05:46 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static int	get_dimension(char *line, int *dimension, int start, int max_dim)
{
	int	holder;

	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	*dimension = ft_atoi_length(line + start, &holder);
	if (*dimension < 1)
		return (-RESOLUTION);
	if (*dimension > max_dim)
		*dimension = max_dim;
	return (start + holder);
}

int			get_resolution(char *line, void **entities)
{
	int				start;
	int				max_width;
	int				max_height;
	t_resolution	*resolution;

	if (entities[RESOLUTION])
		return (-RESOLUTION);
	if (!(resolution = malloc(sizeof(t_resolution))))
		return (-RESOLUTION);
	entities[RESOLUTION] = (void *)resolution;
	//mlx_get_screen_size(((t_display *)entities[DISPLAY])->mlx_ptr, \
	//	&max_width, &max_height);
	max_width = 2000;
	max_height = 2000;
	start = update_start(line, 1);
	if (start == -1)
		return (-RESOLUTION);
	start = get_dimension(line, &(resolution->width), start, max_width);
	start = update_start(line, start);
	if (start == -1)
		return (-RESOLUTION);
	start = get_dimension(line, &(resolution->height), start, max_height);
	return (check_end_entity_info(line, start, RESOLUTION));
}
