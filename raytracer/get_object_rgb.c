/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:58:16 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 20:11:02 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	get_object_rgb(void *object, int type)
{
	if (type == LIGHT)
		return (((t_light *)object)->rgb);
	if (type == SPHERE)
		return (((t_sphere *)object)->rgb);
	if (type == PLANE)
		return (((t_plane *)object)->rgb);
	if (type == SQUARE)
		return (((t_square *)object)->rgb);
	if (type == CYLINDER)
		return (((t_cylinder *)object)->rgb);
	return (((t_triangle *)object)->rgb);
}
