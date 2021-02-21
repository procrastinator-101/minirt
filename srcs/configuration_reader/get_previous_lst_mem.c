/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_previous_lst_mem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:46:49 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/18 20:09:27 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	*get_previous_lst_mem(void *lst_mem, int type)
{
	if (type == CAMERA)
		return (((t_camera *)lst_mem)->previous);
	if (type == LIGHT)
		return (((t_light *)lst_mem)->previous);
	return (0);
}
