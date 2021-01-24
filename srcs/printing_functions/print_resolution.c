/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:24:45 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 16:40:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_resolution(t_resolution *resolution)
{
	if (!resolution)
		return ;
	printf("\n\n====================================");
	printf(" RESOLUTION	");
	printf("====================================\n");
	printf("width = %d\n", resolution->width);
	printf("height = %d\n", resolution->height);
	printf("==========================================");
	printf("==========================================\n");
}
