/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_coord_3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:18:08 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/05 14:49:42 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_coord_3d(t_coord_3d point)
{
	printf("x = %f\n", point.x);
	printf("y = %f\n", point.y);
	printf("z = %f\n", point.z);
}
