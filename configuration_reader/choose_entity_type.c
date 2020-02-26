/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_entity_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:05:26 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 16:36:39 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	*choose_entity_type(void *tail, int type)
{
	if (type == CAMERA)
		return (((t_camera *)tail)->next);
	if (type == LIGHT)
		return (((t_light *)tail)->next);
	if (type == SPHERE)
		return (((t_sphere *)tail)->next);
	if (type == PLANE)
		return (((t_plane *)tail)->next);
	if (type == SQUARE)
		return (((t_square *)tail)->next);
	if (type == CYLINDER)
		return (((t_cylinder *)tail)->next);
	if (type == TRIANGLE)
		return (((t_triangle *)tail)->next);
	return (0);
}
