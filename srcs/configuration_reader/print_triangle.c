/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:46:28 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/07 13:11:48 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	print_triangle(t_triangle *triangle)
{
	while (triangle)
	{
		printf("\n\n=========== TRIANGLE        ===========\n");
		print_coord_3d(triangle->p1);
		print_coord_3d(triangle->p2);
		print_coord_3d(triangle->p3);
		print_texture(&(triangle->texture));
		printf("\n\n");
		triangle = triangle->next;
	}
}
