/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:27:58 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 11:35:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_plane(t_plane *plane)
{
	while (plane)
	{
		printf("\n\n===========	PLANE	===========\n");
		print_coord_3d(plane->position);
		print_3d_basis(plane->basis);
		print_texture(&(plane->texture));
		plane = plane->next;
	}
}
