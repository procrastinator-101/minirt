/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 09:57:39 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/23 11:55:37 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	rotate_sphere(t_sphere *sphere, t_smat_3d m)
{
	if (sphere->mode == 's')
		return ;
	if (sphere->texture.type[0] == 'r' && !sphere->texture.type[1])
		return ;
	sphere->basis.u = smat_vec_3d_product(m, sphere->basis.u);
	sphere->basis.v = smat_vec_3d_product(m, sphere->basis.v);
	sphere->basis.w = smat_vec_3d_product(m, sphere->basis.w);
	normalise_3d_vec(&(sphere->basis.u));
	normalise_3d_vec(&(sphere->basis.v));
	normalise_3d_vec(&(sphere->basis.w));
}
