/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sphere_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:51:17 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/14 12:37:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	update_sphere_mode(t_sphere *sphere)
{
	double	len;

	if (sphere->mode == INTERACTIVE_MODE)
		len = sphere->radius * 2 * M_PI;
	else
		len = sphere->radius * 2;
	if (sphere->texture.type[0] == UV_MAP)
	{
		sphere->texture.uv_map.u_scale = len / sphere->texture.uv_map.width;
		sphere->texture.uv_map.v_scale = len / sphere->texture.uv_map.height;
	}
	if (sphere->texture.type[1] == BUMP_MAP)
	{
		sphere->texture.bump_map.u_scale = len / sphere->texture.\
			bump_map.width;
		sphere->texture.bump_map.v_scale = len / sphere->texture.\
			bump_map.height;
	}
}
