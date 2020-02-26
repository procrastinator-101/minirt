/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vector_3d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:19:47 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 18:24:45 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	print_vector_3d(t_vector_3d vector)
{
	printf("X = %f\n", vector.x);
	printf("Y = %f\n", vector.y);
	printf("Z = %f\n", vector.z);
}
