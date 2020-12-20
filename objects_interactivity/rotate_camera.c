/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:42:43 by youness           #+#    #+#             */
/*   Updated: 2020/06/22 13:45:46 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	rotate_camera(t_camera *camera, t_smat_3d m)
{
	camera->screen.u = smat_vec_3d_product(m, camera->screen.u);
	camera->screen.v = smat_vec_3d_product(m, camera->screen.v);
	camera->screen.w = smat_vec_3d_product(m, camera->screen.w);
	normalise_3d_vec(&(camera->screen.u));
	normalise_3d_vec(&(camera->screen.v));
	normalise_3d_vec(&(camera->screen.w));
}
