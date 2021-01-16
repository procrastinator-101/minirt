/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:19:27 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/18 19:19:31 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	ft_update_next(void *lst_mem, void *next, int type)
{
	if (type == CAMERA)
		((t_camera *)lst_mem)->next = next;
	if (type == LIGHT)
		((t_light *)lst_mem)->next = next;
	else if (type == SPHERE)
		((t_sphere *)lst_mem)->next = next;
	else if (type == PLANE)
		((t_plane *)lst_mem)->next = next;
	else if (type == SQUARE)
		((t_square *)lst_mem)->next = next;
	else if (type == CYLINDER)
		((t_cylinder *)lst_mem)->next = next;
	else if (type == TRIANGLE)
		((t_triangle *)lst_mem)->next = next;
	else if (type == CONE)
		((t_cone *)lst_mem)->next = next;
	else if (type == CUBE)
		((t_cube *)lst_mem)->next = next;
	else if (type == PYRAMID)
		((t_pyramid *)lst_mem)->next = next;
}
