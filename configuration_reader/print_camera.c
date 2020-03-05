/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:04:35 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/05 18:16:06 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void		print_camera(void **entities)
{
	t_camera	*camera;

	camera = entities[CAMERA];
	if (!camera)
		return ;
	printf("\n\n===========	CAMERA	===========\n");
	print_coord_3d(camera->position);
	print_coord_3d(camera->orientation_vec);
	printf("fov = %d\n\n\n", camera->fov);
	camera = camera->next;
	while (camera != entities[CAMERA])
	{
		printf("\n\n===========	CAMERA	===========\n");
		print_coord_3d(camera->position);
		print_coord_3d(camera->orientation_vec);
		printf("fov = %d\n\n\n", camera->fov);
		camera = camera->next;
	}
}
