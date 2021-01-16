/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:41:49 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/26 16:44:15 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	rgb_cmp(t_rgb a, t_rgb b, double margin)
{
	if (fabs(a.red - b.red) > margin)
		return (1);
	if (fabs(a.green - b.green) > margin)
		return (1);
	if (fabs(a.blue - b.blue) > margin)
		return (1);
	return (0);
}
