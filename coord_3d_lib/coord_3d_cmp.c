/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_3d_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:44:21 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/14 12:03:46 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coord_3d_lib.h"

int	coord_3d_cmp(t_coord_3d a, t_coord_3d b)
{
	if (fabs(a.x - b.x) > EPSILON)
		return (0);
	if (fabs(a.y - b.y) > EPSILON)
		return (0);
	if (fabs(a.z - b.z) > EPSILON)
		return (0);
	return (1);
}
