/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:40:42 by youness           #+#    #+#             */
/*   Updated: 2020/12/23 09:59:18 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	rotate_object(void *object, t_smat_3d m, int type)
{
	if (type == CAMERA)
		rotate_camera(object, m);
	else if (type == SPHERE)
		rotate_sphere(object, m);
	else if (type == PLANE)
		rotate_plane(object, m);
	else if (type == SQUARE)
		rotate_square(object, m);
	else if (type == CYLINDER)
		rotate_cylinder(object, m);
	else if (type == TRIANGLE)
		rotate_triangle(object, m);
	else if (type == CONE)
		rotate_cone(object, m);
	else if (type == CUBE)
		rotate_cube(object, m);
	else if (type == PYRAMID)
		rotate_pyramid(object, m);
}
