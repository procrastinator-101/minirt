/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:58:16 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 18:01:26 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_rgb	get_object_rgb(void *object, int type)
{
	if (type == CAMERA)
		return (((t_camera *)tail)->rgb);
	if (type == LIGHT)
		return (((t_light *)tail)->rgb);
	if (type == SPHERE)
		return (((t_sphere *)tail)->rgb);
	if (type == PLANE)
		return (((t_plane *)tail)->rgb);
	if (type == SQUARE)
		return (((t_square *)tail)->rgb);
	if (type == CYLINDER)
		return (((t_cylinder *)tail)->rgb);
	return (((t_triangle *)tail)->rgb);
}
