/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:04:35 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 16:39:15 by yarroubi         ###   ########.fr       */
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
	printf("\nwidth = %f\n", screen.width);
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
		printf("\n\n======================================");
		printf(" CAMERA ");
		printf("======================================\n");
		print_coord_3d(camera->position);
		printf("fov = %d\n", camera->fov);
		printf("\n---- screen ----\n");
		print_screen(camera->screen);
		print_pixel(camera->pixel);
		printf("==========================================");
		printf("==========================================\n");
		camera = camera->next != tail ? camera->next : 0;
	}
}
