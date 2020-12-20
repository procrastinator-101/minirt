/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 21:11:51 by youness           #+#    #+#             */
/*   Updated: 2020/06/21 21:13:10 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	translate_cylinder(t_cylinder *cylinder, t_coord_3d v)
{
	cylinder->position = coord_3d_plus(cylinder->position, v);
}
