/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:27:58 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/04 13:08:08 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_plane(t_plane *plane)
{
	while (plane)
	{
		printf("\n\n===========	PLANE	===========\n");
		print_coord_3d(plane->position);
		print_3d_basis(plane->basis);
		print_texture(&(plane->texture));
		printf("\n\n");
		plane = plane->next;
	}
}
