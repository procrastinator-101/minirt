/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:35:37 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/04 13:06:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	print_square(t_square *square)
{
	while (square)
	{
		printf("\n\n=========== SQUARE  ===========\n");
		print_3d_basis(square->basis);
		printf("radius = %f\n", square->radius);
		print_texture(&(square->texture));
		printf("\n\n");
		square = square->next;
	}
}
