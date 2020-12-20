/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_linear_dependency.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:02:39 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/14 12:04:27 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coord_3d_lib.h"

int	check_linear_dependency(t_coord_3d a, t_coord_3d b)
{
	double	det;

	det = a.x * b.y - a.y * b.x - a.x * b.z + a.z * b.x + a.y * b.z - a.z * b.y;
	return (det != 0.0 ? 0 : 1);
}
