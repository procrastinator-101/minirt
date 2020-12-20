/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:38:42 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 16:40:59 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coord_3d_lib.h"

t_coord_3d	scalar_product(t_coord_3d v, double scalar)
{
	v.x *= scalar;
	v.y *= scalar;
	v.z *= scalar;
	return (v);
}
