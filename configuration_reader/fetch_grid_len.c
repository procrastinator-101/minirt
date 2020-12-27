/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_grid_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:15:21 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/27 17:15:34 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int	fetch_grid_len(char *line, double *grid_len, int start)
{
	int		holder;

	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	*grid_len = ft_atod_length(line + start, &holder);
	if (*grid_len < 0.0)
		return (-1);
	*grid_len = ft_max(*grid_len, 0.5);
	return (start + holder);
}
