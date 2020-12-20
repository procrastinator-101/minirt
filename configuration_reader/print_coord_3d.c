/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_coord_3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:18:08 by yarroubi          #+#    #+#             */
/*   Updated: 2020/06/24 14:21:34 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_coord_3d(t_coord_3d point)
{
	printf("[%f\t\t%f\t\t%f\t]\n", point.x, point.y, point.z);
}
