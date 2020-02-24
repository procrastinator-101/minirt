/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:50:58 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/23 21:44:48 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	fetch_ratio(char *line, t_ambient *ambient_light)
{
	int	start;

	ambient_light->ratio = ft_atoi(line + 2);
	if (ambient_light->ratio > 1.0 || line[2] == '-')
		return (-1);
	if (line[3] == '.')
		ambient_light->ratio = ft_atoi(line + 4);
	if (ambient_light->ratio != 0.0)
		start = (int)log10(ambient_light->ratio) + 1;
	else
		start = 1;
	ambient_light->ratio /= pow(10.0, start);
	return (start);
}

static int	fetch_rgb(char *line, t_ambient *ambient_light, int start)
{
	ambient_light->red = ft_atoi(line + start);
	if (ambient_light->red > 255 || ambient_light->red < 0)
		return (-1);
	start += (int)log10(ambient_light->red) + 2;
	printf("start = %d\n", start);
	ambient_light->green = ft_atoi(line + start);
	if (ambient_light->green < 0 || ambient_light->green > 255)
		return (-1);
	start += (int)log10(ambient_light->green) + 2;
	printf("start = %d\n", start);
	ambient_light->blue = ft_atoi(line + start);
	if (ambient_light->blue < 0 ||  ambient_light->blue > 255)
		return (-1);
	printf("start = %d\n", start);
	return (1);
}

int			get_ambient_light(char *line, void **entities)
{
	int			start;
	t_ambient	*ambient_light;

	if (!(ambient_light = malloc(sizeof(t_ambient))))
		return (0);
	start = fetch_ratio(line, ambient_light) + 4;
	if (start == -1)
		return (0);
	printf("start = %d\n", start);
	if (fetch_rgb(line, ambient_light, start) == -1)
		return (0);
	return (1);
}
