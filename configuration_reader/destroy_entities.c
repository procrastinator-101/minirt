/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_entities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:04:13 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/02 08:09:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	destroy_entities(void **entities)
{
	int			i;
	t_display	*display;

	i = 0;
	while (++i < DISPLAY)
	{
		if (i < CAMERA || (i >= SKYBOX && i <= ANTI_ALIASING))
			free(entities[i]);
		else if (i == CAMERA || i == LIGHT)
			ft_dclst_destroy(entities + i, i);
		else
			ft_lst_destroy(entities + i, i);
	}
	display = entities[DISPLAY];
	if (display->mlx_ptr && display->img_ptr)
		mlx_destroy_image(display->mlx_ptr, display->img_ptr);
	if (display->mlx_ptr && display->win_ptr)
		mlx_destroy_window(display->mlx_ptr, display->win_ptr);
	free(entities);
}
