/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:37:22 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/07 19:56:22 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <string.h>
#include <stdio.h>

double   title_point_coordinates(double c)
{
    double  tmp;

    tmp = c;
    c = fabs(c);
    if (c > PLANE_TILTING_SIZE / 2.0)
    {
        c += PLANE_TILTING_SIZE / 2.0;
        c = fmod(c, PLANE_TILTING_SIZE);//for mapping the image multiple times
        if (c > PLANE_TILTING_SIZE / 2.0)
            c -= PLANE_TILTING_SIZE / 2.0;
        else
            c = PLANE_TILTING_SIZE / 2.0 - c;
    }
    return (tmp < 0 ? -c : c);
}

int main() 
{
	double	x = 171452.0255;
	double	y = -18795.265;
	printf("x = %f	|	y = %f\n", x, y);
	x = title_point_coordinates(x);
	y = title_point_coordinates(y);
	printf("x = %f	|	y = %f\n", x, y);

	return 0;
}
