/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:35:37 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/03 10:02:16 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	display_element(t_square *square)
{
	if (!square)
		return ;
	print_point_3d(square->square_point);
	print_vector_3d(square->orientation_vec);
	printf("height = %f\n", square->height);
	print_rgb(square->rgb);
	printf("\n\n");
	display_element(square->next);
}

void		print_square(void **entities)
{
	t_square	*square;

	square = entities[SQUARE];
	printf("\n\n===========	SQUARE	===========\n");
	display_element(square);
}
