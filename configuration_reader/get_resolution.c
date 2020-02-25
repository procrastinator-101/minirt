/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:24:09 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/25 12:07:17 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	get_resolution(char *line, void **entities)
{
	int				start;
	t_resolution	*resolution;

	if (entities[0])
		return (0);
	if (!(resolution = malloc(sizeof(t_resolution))))
		return (0);
	entities[0] = (void *)resolution;
	start = find_next_arg(line, 2);
	if (!ft_isdigit(line[start]))
		return (0);
	resolution->width = ft_atoi(line + start);
	if (resolution->width < 1)
		return (0);
	start += (int)log10(resolution->width) + 1;
	start = find_next_arg(line, start);
	if (!ft_isdigit(line[start]))
		return (0);
	resolution->height = ft_atoi(line + start);
	if (resolution->height < 1)
		return (0);
	return (1);
}
