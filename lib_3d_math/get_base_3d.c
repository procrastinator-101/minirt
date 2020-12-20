/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_base_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:02:39 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/28 12:19:47 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_3d_math.h"

void	get_base_3d(t_coord_3d *w, t_coord_3d *v, t_coord_3d *u)
{
	t_coord_3d up;

	up.x = 0;
	up.y = 1;
	up.z = 0;
	if (check_linear_dependency(*w, up))
	{
		up.x = 1;
		up.y = 0;
	}
	*u = cross_product(up, *w);
	*v = cross_product(*w, *u);
	normalise_3d_vec(u);
	normalise_3d_vec(v);
}
