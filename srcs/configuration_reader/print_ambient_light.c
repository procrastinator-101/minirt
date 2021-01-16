/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:01:02 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/30 16:47:59 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	print_ambient_light(t_ambient *ambient)
{
	if (!ambient)
		return ;
	printf("\n\n===========	AMBIENT	===========\n");
	printf("ratio = %f\n", ambient->ratio);
	print_rgb(ambient->rgb);
}
