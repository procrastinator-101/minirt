/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:46:28 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/05 17:54:08 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	display_element(t_triangle *triangle)
{
	printf("\n\n===========	TRIANGLE	===========\n");
	print_coord_3d(triangle->first_point);
	print_coord_3d(triangle->second_point);
	print_coord_3d(triangle->third_point);
	print_rgb(triangle->rgb);
	printf("\n\n");
}

void		print_triangle(void **entities)
{
	t_triangle	*triangle;

	triangle = entities[TRIANGLE];
	if (!triangle)
		return ;
	display_element(triangle);
	triangle = triangle->next;
	while (triangle != entities[TRIANGLE])
	{
		display_element(triangle);
		triangle = triangle->next;
	}
}
