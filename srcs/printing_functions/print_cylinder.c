/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:41:31 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 16:52:33 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_cylinder(t_cylinder *cylinder)
{
	while (cylinder)
	{
		printf("\n\n=====================================");
		printf(" CYLINDER ");
		printf("=====================================\n");
		print_coord_3d(cylinder->position);
		printf("radius = %f\n", cylinder->radius);
		printf("height = %f\n", cylinder->height);
		printf("caps   = %d\n", cylinder->caps);
		print_3d_basis(cylinder->basis);
		print_texture(&(cylinder->texture));
		printf("==========================================");
		printf("==========================================\n");
		cylinder = cylinder->next;
	}
}
