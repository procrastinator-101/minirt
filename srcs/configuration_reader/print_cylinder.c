/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:41:31 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/04 13:02:16 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	print_cylinder(t_cylinder *cylinder)
{
	while (cylinder)
	{
		printf("\n\n=========== CYLINDER        ===========\n");
		print_coord_3d(cylinder->position);
		print_3d_basis(cylinder->basis);
		printf("radius = %f\n", cylinder->radius);
		printf("height = %f\n", cylinder->height);
		print_texture(&(cylinder->texture));
		printf("\n\n");
		cylinder = cylinder->next;
	}
}
