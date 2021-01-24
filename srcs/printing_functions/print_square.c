/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:35:37 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 11:49:21 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_square(t_square *square)
{
	while (square)
	{
		if (!square->parent)
		{
			printf("\n\n=========== SQUARE  ===========\n");
			print_coord_3d(square->position);
			printf("radius = %f\n", square->radius);
			print_3d_basis(square->basis);
			print_texture(&(square->texture));
		}
		square = square->next;
	}
}
