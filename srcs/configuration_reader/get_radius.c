/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_radius.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 21:04:05 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/19 12:08:57 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

int	get_radius(char *line, double *radius, int start)
{
	int		holder;

	if (!ft_isnumber(line + start))
		return (-1);
	*radius = ft_atod_length(line + start, &holder) / 2.0;
	if (*radius < 0.0)
		return (-1);
	return (update_start(line, start + holder));
}
