/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:37:22 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/25 12:51:58 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <string.h>
#include <stdio.h>

t_coord_3d  tilt_point_coordinates(t_plane *plane, t_coord_3d p)
{
    double      x;
    double      y;
    t_coord_3d  p1;

	p = coord_3d_minus(p, plane->position);
    x = fabs(fmod(dot_product(p, plane->basis.u), PLANE_TILTING_SIZE));
    y = fabs(fmod(dot_product(p, plane->basis.v), PLANE_TILTING_SIZE));
	printf("x = %f\n\t\ty = %f\n", x, y);
    if (x > PLANE_TILTING_SIZE / 2.0)
        x = PLANE_TILTING_SIZE / 2.0 - x;
    if (y > PLANE_TILTING_SIZE / 2.0)
        y = PLANE_TILTING_SIZE / 2.0 - y;
	printf("x = %f\n\t\ty = %f\n", x, y);
    p1 = coord_3d_plus(plane->position, scalar_product(plane->basis.u, x));
    p1 = coord_3d_plus(p1, scalar_product(plane->basis.v, y));
    return (p1);
}

int main() 
{
	t_plane		plane;
	t_coord_3d	p;

	plane.position = get_coord_3d(0,0,0);
	plane.basis.u = get_coord_3d(1,0,0);
	plane.basis.v = get_coord_3d(0,1,0);

	p = get_coord_3d(40, 30, 0);
	p = tilt_point_coordinates(&plane, p);
	print_coord_3d(p);

	return 0;
}
