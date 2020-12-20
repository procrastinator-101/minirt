/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_skybox.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 10:03:25 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/08 18:43:06 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	translate_skybox(t_skybox *skybox, t_camera *camera)
{
	int			i;
	t_coord_3d	v;

	i = -1;
	while (++i < 6)
	{
		v = scalar_product(skybox->faces[i].basis.w, skybox->faces[i].radius);
		skybox->faces[i].position = coord_3d_plus(camera->position, v);
	}
}
