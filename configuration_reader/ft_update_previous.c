/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_previous.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:19:36 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/18 20:14:20 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	ft_update_previous(void *lst_mem, void *previous, int type)
{
	if (type == CAMERA)
		((t_camera *)lst_mem)->previous = previous;
	if (type == LIGHT)
		((t_light *)lst_mem)->previous = previous;
}
