/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:27:58 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 18:53:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	display_element(t_plane *plane)
{
	if (!plane)
		return ;
	print_point_3d(plane->plane_point);
	print_vector_3d(plane->orientation_vec);
	print_rgb(plane->rgb);
	display_element(plane->next);
}

void		print_plane(void **entities)
{
	t_plane	*plane;

	plane = entities[PLANE];
	display_element(plane);
}
