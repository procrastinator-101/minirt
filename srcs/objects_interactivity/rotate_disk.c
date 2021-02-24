/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_disk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:26:41 by yarroubi          #+#    #+#             */
/*   Updated: 2021/02/24 16:27:39 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	rotate_disk(t_disk *disk, t_smat_3d m)
{
	disk->basis.u = smat_vec_3d_product(m, disk->basis.u);
	disk->basis.v = smat_vec_3d_product(m, disk->basis.v);
	disk->basis.w = smat_vec_3d_product(m, disk->basis.w);
	normalise_3d_vec(&(disk->basis.u));
	normalise_3d_vec(&(disk->basis.v));
	normalise_3d_vec(&(disk->basis.w));
}
