/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_3d_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:44:21 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/16 17:10:49 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_3d_math.h"

t_coord_3d	null_3d_vec(void)
{
	t_coord_3d v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	return (v);
}
