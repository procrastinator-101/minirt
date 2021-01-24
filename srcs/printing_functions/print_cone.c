/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:14:31 by youness           #+#    #+#             */
/*   Updated: 2021/01/24 11:42:25 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_cone(t_cone *cone)
{
	while (cone)
	{
		printf("\n\n===========  CONE        ===========\n");
		print_coord_3d(cone->vertex);
		printf("height = %f\n", cone->height);
		printf("angle = %f\n\n", cone->angle);
		print_3d_basis(cone->basis);
		print_texture(&(cone->texture));
		cone = cone->next;
	}
}
