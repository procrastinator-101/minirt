/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_3d_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:49:13 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 20:49:25 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_3d_math.h"

t_coord_3d	coord_3d_plus(t_coord_3d a, t_coord_3d b)
{
	t_coord_3d	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}
