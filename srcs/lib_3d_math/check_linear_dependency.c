/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_linear_dependency.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:02:39 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/28 12:29:53 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_3d_math.h"

int	check_linear_dependency(t_coord_3d a, t_coord_3d b)
{
	double	t;

	normalise_3d_vec(&a);
	t = dot_product(a, b);
	if (coord_3d_cmp(scalar_product(a, t), b))
		return (1);
	return (0);
}
