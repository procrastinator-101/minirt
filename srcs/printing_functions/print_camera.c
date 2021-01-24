/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:04:35 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 11:59:45 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

static void	print_screen(t_screen screen)
{
	printf("u\t:\t");
	print_coord_3d(screen.u);
	printf("v\t:\t");
	print_coord_3d(screen.v);
	printf("w\t:\t");
	print_coord_3d(screen.w);
	printf("width = %f\n", screen.width);
	printf("height = %f\n", screen.height);
}

void		print_camera(t_camera *camera)
{
	t_camera	*tail;

	if (!camera)
		return ;
	tail = camera;
	while (camera)
	{
		printf("\n\n===========	CAMERA	===========\n");
		print_coord_3d(camera->position);
		printf("fov = %d\n", camera->fov);
		printf("---- screen ----\n");
		print_screen(camera->screen);
		print_pixel(camera->pixel);
		camera = camera->next != tail ? camera->next : 0;
	}
}
