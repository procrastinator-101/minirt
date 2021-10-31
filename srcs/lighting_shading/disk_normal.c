/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:20:33 by yarroubi          #+#    #+#             */
/*   Updated: 2021/02/24 16:24:38 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_coord_3d	disk_normal(t_disk *disk, t_coord_3d p, t_coord_3d d)
{
	t_coord_3d	n;

	if (dot_product(disk->basis.w, d) < 0.0)
		n = disk->basis.w;
	else
		n = scalar_product(disk->basis.w, -1);
	if (disk->texture.type[1] == BUMP_MAP)
		n = get_bump_normal(&(disk->texture.bump_map), &(disk->basis), n, \
				coord_3d_sub(p, disk->center));
	else if (disk->texture.type[1] == WAVE)
		n = get_wave_normal(disk->basis, disk->center, p, \
				get_wave_length(disk->texture));
	return (n);
}
