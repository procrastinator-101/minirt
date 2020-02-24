/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:24:09 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/24 19:42:10 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	get_resolution(char *line, void **entities)
{
	int				start;
	t_resolution	*resolution;

	if (!(resolution = malloc(sizeof(t_resolution))))
		return (0);
	entities[0] = (void *)resolution;
	if (!ft_isdigit(line[2]))
		return (0);
	resolution->width = ft_atoi(line + 2);
	if (resolution->width < 1)
		return (0);
	start = (int)log10(resolution->width) + 2;
	if (!ft_isdigit(line[start]))
		return (0);
	resolution->height = ft_atoi(line + start + 2);
	if (resolution->height < 1)
		return (0);
	return (1);
}
