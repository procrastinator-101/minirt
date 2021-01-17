/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lst_mem_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:16:25 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/17 17:32:01 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

t_texture	*get_lst_mem_texture(void *lst_mem, int type)
{
	if (type == SPHERE)
		return (&(((t_sphere *)lst_mem)->texture));
	if (type == PLANE)
		return (&(((t_plane *)lst_mem)->texture));
	if (type == SQUARE)
		return (&(((t_square *)lst_mem)->texture));
	if (type == CYLINDER)
		return (&(((t_cylinder *)lst_mem)->texture));
	if (type == TRIANGLE)
		return (&(((t_triangle *)lst_mem)->texture));
	if (type == CONE)
		return (&(((t_cone *)lst_mem)->texture));
	if (type == CUBE)
		return (&(((t_cube *)lst_mem)->texture));
	if (type == PYRAMID)
		return (&(((t_pyramid *)lst_mem)->texture));
	return (0);
}
