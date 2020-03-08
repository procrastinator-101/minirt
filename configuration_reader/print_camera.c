/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:04:35 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/08 15:25:53 by yarroubi         ###   ########.fr       */
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
	print_coord_3d(camera->screen.w);
	print_coord_3d(camera->screen.u);
	print_coord_3d(camera->screen.v);
	printf("fov = %d\n\n\n", camera->fov);
	printf("screen_width = %f\n", camera->screen.width);
	printf("screen_height = %f\n", camera->screen.height);
	printf("pixel_width = %f\n", camera->pixel.width);
	printf("pixel_height = %f\n", camera->pixel.height);
	camera = camera->next;
	while (camera != entities[CAMERA])
	{
		printf("\n\n===========	CAMERA	===========\n");
		print_coord_3d(camera->position);
		print_coord_3d(camera->screen.w);
		print_coord_3d(camera->screen.u);
		print_coord_3d(camera->screen.v);
		printf("fov = %d\n\n\n", camera->fov);
		printf("screen_width = %f\n", camera->screen.width);
		printf("screen_height = %f\n", camera->screen.height);
		printf("pixel_width = %f\n", camera->pixel.width);
		printf("pixel_height = %f\n", camera->pixel.height);
		camera = camera->next;
	}
}
