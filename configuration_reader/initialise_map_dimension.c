/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_map_dimension.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:47:35 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/03 17:00:26 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	initialise_map_dimension(t_texture *texture)
{
	texture->uv_map.width = texture->width;
	texture->uv_map.height = texture->height;
	texture->bump_map.width = texture->width;
	texture->bump_map.height = texture->height;
}
