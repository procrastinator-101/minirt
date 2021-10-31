/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:06:52 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/31 14:08:46 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/support_functions.h"

double	tilt(double c, double tilting_size)
{
	double	tmp;

	tmp = c;
	c = fabs(c);
	if (c > tilting_size / 2.0)
	{
		c += tilting_size / 2.0;
		c = fmod(c, tilting_size);
		c -= tilting_size / 2.0;
	}
	return (tmp < 0 ? -c : c);
}
