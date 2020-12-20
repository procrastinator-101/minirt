/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:14:31 by youness           #+#    #+#             */
/*   Updated: 2020/11/04 13:01:48 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_cone(t_cone *cone)
{
	while (cone)
	{
		printf("\n\n===========  CONE        ===========\n");
		print_coord_3d(cone->vertex);
		print_3d_basis(cone->basis);
		printf("height = %f\n", cone->height);
		printf("angle = %f\n\n", cone->angle);
		print_texture(&(cone->texture));
		printf("\n\n");
		cone = cone->next;
	}
}
