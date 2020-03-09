/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:27:58 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/05 17:26:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void		print_plane(void **entities)
{
	t_plane	*plane;

	plane = entities[PLANE];
	if (!plane)
		return ;
	printf("\n\n===========	PLANE	===========\n");
	print_coord_3d(plane->position);
	print_coord_3d(plane->v);
	print_rgb(plane->rgb);
	printf("\n\n");
	plane = plane->next;
	while (plane != entities[PLANE])
	{
		printf("\n\n===========	PLANE	===========\n");
		print_coord_3d(plane->position);
		print_coord_3d(plane->v);
		print_rgb(plane->rgb);
		printf("\n\n");
		plane = plane->next;
	}
}
