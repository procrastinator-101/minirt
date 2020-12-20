/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 21:08:05 by youness           #+#    #+#             */
/*   Updated: 2020/06/21 21:09:16 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	translate_sphere(t_sphere *sphere, t_coord_3d v)
{
	sphere->center = coord_3d_plus(sphere->center, v);
}
