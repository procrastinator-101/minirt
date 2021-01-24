/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3d_basis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:03:52 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/04 13:05:08 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_3d_basis(t_3d_basis basis)
{
	printf("u  = ");
	print_coord_3d(basis.u);
	printf("v  = ");
	print_coord_3d(basis.v);
	printf("w  = ");
	print_coord_3d(basis.w);
}
