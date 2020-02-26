/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:41:31 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 18:45:15 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	display_element(t_cylinder *cylinder)
{
	if (!cylinder)
		return ;
	print_point_3d(cylinder->cylinder_point);
	print_vector_3d(cylinder->orientation_vec);
	printf("diameter = %f\n", cylinder->diameter);
	printf("height = %f\n", cylinder->height);
	print_rgb(cylinder->rgb);
	display_element(cylinder->next);
}

void		print_cylinder(void **entities)
{
	t_cylinder	*cylinder;

	cylinder = entities[CYLINDER];
	display_element(cylinder);
}
