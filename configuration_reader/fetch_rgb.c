/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:16:26 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/03 09:57:29 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int	fetch_rgb(char *line, t_rgb *rgb, int start)
{
	int holder;

	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	rgb->red = ft_atoi_length(line + start, &holder);
	if (rgb->red < 0 || rgb->red > 255)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	rgb->green = ft_atoi_length(line + start, &holder);
	if (rgb->green < 0 || rgb->green > 255)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	rgb->blue = ft_atoi_length(line + start, &holder);
	if (rgb->blue < 0 || rgb->blue > 255)
		return (-1);
	return (start + holder);
}
