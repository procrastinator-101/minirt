/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution_linux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:44:46 by yarroubi          #+#    #+#             */
/*   Updated: 2021/02/24 14:45:24 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

static int	get_dimension(char *line, int *dimension, int start, int max_dim)
{
	int	holder;

	if (!ft_isnumber(line + start))
		return (-1);
	*dimension = ft_atoi_length(line + start, &holder);
	if (*dimension < 1)
		return (-1);
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
		return (-EMRD);
	if (!(resolution = malloc(sizeof(t_resolution))))
		return (-EMAF);
	entities[RESOLUTION] = resolution;
	ft_get_screen_size(&max_width, &max_height);
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