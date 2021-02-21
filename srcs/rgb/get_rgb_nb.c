/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 18:40:02 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/24 12:49:08 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	ft_is_double_even(double num)
{
	if (num == 0.0 || num == 2.0 || num == 4.0 || num == 6.0 || \
		num == 8.0)
		return (1);
	return (0);
}

int			get_rgb_nb(double x, double y, double grid_len)
{
	double	index;

	x = floor(x / grid_len);
	y = floor(y / grid_len);
	index = fabs(floor(fmod(x + y, 10.0)));
	if (ft_is_double_even(index))
		return (0);
	return (1);
}
