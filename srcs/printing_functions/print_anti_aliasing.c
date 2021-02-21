/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_anti_aliasing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:05:55 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 17:09:53 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_anti_aliasing(t_anti_aliasing *anti_aliasing)
{
	if (!anti_aliasing)
		return ;
	printf("\n\n==================================");
	printf(" ANTI_ALIASING ");
	printf("===================================\n");
	printf("factor = %d\n", anti_aliasing->factor);
	printf("==========================================");
	printf("==========================================\n");
}
