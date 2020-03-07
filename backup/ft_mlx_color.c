/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:12:31 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/06 16:34:26 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int ft_mlx_color(int rgb)
{
	int				color;
	unsigned char	*str;
	unsigned char	*ptr;

	str = (unsigned char *)(&rgb);
	ptr = (unsigned char *)(&color);
	ptr[0] = 0;
	ptr[0] = 0;
	return (color);
}
