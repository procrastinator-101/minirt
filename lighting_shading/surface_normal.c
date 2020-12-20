/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/25 14:23:48 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_coord_3d	surface_normal(void *object, t_coord_3d d, t_coord_3d p, int type)
{
	if (type == SPHERE)
		return (sphere_normal(object, p, d));
	if (type == PLANE)
		return (plane_normal(object, p, d));
	if (type == SQUARE)
		return (square_normal(object, p, d));
	if (type == CYLINDER)
		return (cylinder_normal(object, p, d));
	if (type == TRIANGLE)
		return (triangle_normal(object, p, d));
	if (type == CONE)
		return (cone_normal(object, p, d));
	return (null_3d_vec());
}
