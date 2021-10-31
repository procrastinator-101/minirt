/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise_3d_vec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:40:39 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 15:59:43 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_3d_math.h"

void	normalise_3d_vec(t_coord_3d *v)
{
	double	den;

	den = sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
	v->x /= den;
	v->y /= den;
	v->z /= den;
}
