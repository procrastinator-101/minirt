/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:15:44 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/23 10:59:36 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int	get_grid_len(char *line, double *grid_len, int start)
{
	int		holder;

	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	*grid_len = ft_atod_length(line + start, &holder);
	if (*grid_len < 0.0)
		return (-1);
	return (start + holder);
}
