/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:46:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 18:27:37 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_3d_math.h"

double	dot_product(t_coord_3d a, t_coord_3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}