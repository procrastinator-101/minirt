/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:04:35 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/21 12:44:31 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	print_camera(t_camera *camera)
{
	t_camera	*tail;

	if (!camera)
		return ;
	tail = camera;
	while (camera)
	{
		printf("\n\n===========	CAMERA	===========\n");
		print_coord_3d(camera->position);
		print_coord_3d(camera->screen.u);
		print_coord_3d(camera->screen.v);
		print_coord_3d(camera->screen.w);
		printf("fov = %d\n\n\n", camera->fov);
		printf("screen_width = %f\n", camera->screen.width);
		printf("screen_height = %f\n", camera->screen.height);
		printf("pixel_width = %f\n", camera->pixel.width);
		printf("pixel_height = %f\n", camera->pixel.height);
		camera = camera->next != tail ? camera->next : 0;
	}
}
