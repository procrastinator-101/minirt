/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_entities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:04:13 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/18 12:22:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	destroy_entities(void **entities)
{
	int			i;
	t_display	*display;

	i = 0;
	while (++i < DISPLAY)
	{
		if (i < CAMERA || i == ANTI_ALIASING || i == SEPIA)
			free(entities[i]);
		else if (i == CAMERA || i == LIGHT)
			ft_dclst_destroy(entities + i, i);
		else if (i == SKYBOX)
			ft_destroy_lst_mem(entities[i], i, entities[DISPLAY]);
		else
			ft_lst_destroy(entities + i, i, entities[DISPLAY]);
	}
	display = entities[DISPLAY];
	if (display->mlx_ptr && display->img_ptr)
		mlx_destroy_image(display->mlx_ptr, display->img_ptr);
	if (display->mlx_ptr && display->win_ptr)
		mlx_destroy_window(display->mlx_ptr, display->win_ptr);
	free(entities);
}
