/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:16:26 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/19 12:05:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

int	fetch_rgb(char *line, t_rgb *rgb, int start)
{
	int holder;

	if (!ft_isnumber(line + start))
		return (-1);
	rgb->red = ft_atoi_length(line + start, &holder) / 255.0;
	if (rgb->red < 0 || rgb->red > 1.0)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isnumber(line + start))
		return (-1);
	rgb->green = ft_atoi_length(line + start, &holder) / 255.0;
	if (rgb->green < 0 || rgb->green > 1.0)
		return (-1);
	start += holder + 1;
	if (line[start - 1] != ',')
		return (-1);
	if (!ft_isnumber(line + start))
		return (-1);
	rgb->blue = ft_atoi_length(line + start, &holder) / 255.0;
	if (rgb->blue < 0 || rgb->blue > 1.0)
		return (-1);
	return (start + holder);
}
