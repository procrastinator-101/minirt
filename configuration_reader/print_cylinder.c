/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:41:31 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/05 17:11:52 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	display_element(t_cylinder *cylinder)
{
	printf("\n\n===========	CYLINDER	===========\n");
	print_coord_3d(cylinder->cylinder_point);
	print_coord_3d(cylinder->orientation_vec);
	printf("diameter = %f\n", cylinder->diameter);
	printf("height = %f\n", cylinder->height);
	print_rgb(cylinder->rgb);
	printf("\n\n");
}

void		print_cylinder(void **entities)
{
	t_cylinder	*cylinder;

	cylinder = entities[CYLINDER];
	if (!cylinder)
		return ;
	display_element(cylinder);
	cylinder = cylinder->next;
	while (cylinder != entities[CYLINDER])
	{
		display_element(cylinder);
		cylinder = cylinder->next;
	}
}
