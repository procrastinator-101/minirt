/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:04:35 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/03 10:01:57 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	display_element(t_camera *camera)
{
	if (!camera)
		return ;
	print_point_3d(camera->position);
	print_vector_3d(camera->orientation_vec);
	printf("fov = %d\n\n\n", camera->fov);
	display_element(camera->next);
}

void		print_camera(void **entities)
{
	t_camera	*camera;

	camera = entities[CAMERA];
	printf("\n\n===========	CAMERA	===========\n");
	display_element(camera);
}
