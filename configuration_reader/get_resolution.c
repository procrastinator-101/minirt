/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:24:09 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/23 18:47:03 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	get_resolution(char *line, void **entities)
{
	t_resolution	*resolution;

	if (!(resolution = malloc(sizeof(t_resolution))))
		return (0);
	resolution->width = ft_atoi(line + 2);
	if (resolution->width < 1)
		return (0);
	resolution->height = ft_atoi(line + 3 + log10(resolution->width));
	if (!resolution->height < 1)
		return (0);
	entities[0] = (void *)resolution;
	return (1);
}
