/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:01:02 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 16:43:30 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_ambient_light(t_ambient *ambient)
{
	if (!ambient)
		return ;
	printf("\n\n=====================================");
	printf(" AMBIENT ");
	printf("======================================\n");
	printf("ratio = %f\n", ambient->ratio);
	print_rgb(ambient->rgb);
	printf("==========================================");
	printf("==========================================\n");
}
