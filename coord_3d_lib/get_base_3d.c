/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_base_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:02:39 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 20:56:53 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coord_3d_lib.h"

void	get_base_3d(t_coord_3d *w, t_coord_3d *v, t_coord_3d *u)
{
	t_coord_3d up;

	up.x = 0;
	up.y = 1;
	up.z = 0;
	if (coord_3d_cmp(up, *w))
	{
		up.x = 1;
		up.y = 0;
	}
	*u = cross_product(*w, up);
	*v = cross_product(*u, *w);
}
