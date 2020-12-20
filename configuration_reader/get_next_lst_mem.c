/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lst_mem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:33:52 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/30 16:22:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	*get_next_lst_mem(void *lst_mem, int type)
{
	if (type == CAMERA)
		return (((t_camera *)lst_mem)->next);
	if (type == LIGHT)
		return (((t_light *)lst_mem)->next);
	if (type == SPHERE)
		return (((t_sphere *)lst_mem)->next);
	if (type == PLANE)
		return (((t_plane *)lst_mem)->next);
	if (type == SQUARE)
		return (((t_square *)lst_mem)->next);
	if (type == CYLINDER)
		return (((t_cylinder *)lst_mem)->next);
	if (type == TRIANGLE)
		return (((t_triangle *)lst_mem)->next);
	if (type == CONE)
		return (((t_cone *)lst_mem)->next);
	if (type == CUBE)
		return (((t_cube *)lst_mem)->next);
	if (type == CUBE)
		return (((t_cube *)lst_mem)->next);
	if (type == PYRAMID)
		return (((t_pyramid *)lst_mem)->next);
	return (0);
}
