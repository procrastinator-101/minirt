/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wave_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:17:21 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/26 10:17:06 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	get_wave_length(t_texture texture)
{
	return (ft_min(ft_max(texture.width, texture.height) / 10.0), 10.0);
}
