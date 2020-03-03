/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:46:28 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/03 10:03:15 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	display_element(t_triangle *triangle)
{
	if (!triangle)
		return ;
	print_point_3d(triangle->first_point);
	print_point_3d(triangle->second_point);
	print_point_3d(triangle->third_point);
	print_rgb(triangle->rgb);
	printf("\n\n");
	display_element(triangle->next);
}

void		print_triangle(void **entities)
{
	t_triangle	*triangle;

	triangle = entities[TRIANGLE];
	printf("\n\n===========	TRIANGLE	===========\n");
	display_element(triangle);
}
