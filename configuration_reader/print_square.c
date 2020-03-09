/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:35:37 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/05 17:52:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	display_element(t_square *square)
{
	printf("\n\n===========	SQUARE	===========\n");
	print_coord_3d(square->position);
	print_coord_3d(square->v);
	printf("height = %f\n", square->height);
	print_rgb(square->rgb);
	printf("\n\n");
}

void		print_square(void **entities)
{
	t_square	*square;

	square = entities[SQUARE];
	if (!square)
		return ;
	display_element(square);
	square = square->next;
	while (square != entities[SQUARE])
	{
		display_element(square);
		square = square->next;
	}
}
