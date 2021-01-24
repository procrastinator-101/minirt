/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_skybox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:27:07 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 17:02:29 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_skybox(t_skybox *skybox)
{
	int	i;

	if (!skybox)
		return ;
	printf("\n\n======================================");
	printf(" SKYBOX ");
	printf("======================================\n");
	i = -1;
	while (++i < 6)
	{
		printf("***** face %d *****\n", i);
		print_coord_3d(skybox->faces[i].position);
		printf("radius = %f\n", skybox->faces[i].radius);
		print_3d_basis(skybox->faces[i].basis);
		print_texture(&(skybox->faces[i].texture));
	}
	printf("==========================================");
	printf("==========================================\n");
}
