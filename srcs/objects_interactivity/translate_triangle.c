/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 21:13:47 by youness           #+#    #+#             */
/*   Updated: 2021/01/14 11:35:42 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	translate_triangle(t_triangle *triangle, t_coord_3d v)
{
	triangle->c = coord_3d_add(triangle->c, v);
	triangle->p1 = coord_3d_add(triangle->p1, v);
	triangle->p2 = coord_3d_add(triangle->p2, v);
	triangle->p3 = coord_3d_add(triangle->p3, v);
	triangle->centroid = coord_3d_add(triangle->centroid, v);
}
