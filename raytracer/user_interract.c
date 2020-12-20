/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:59:59 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/01 20:22:03 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	user_interract(void **entities, t_display *display)
{
	mlx_hook(display->win_ptr, KeyPress, KeyPressMask, manage_key, entities);
	mlx_hook(display->win_ptr, ButtonPress, ButtonPressMask, \
		manage_mouse_hits, entities);
	//mlx_hook(display->win_ptr, MotionNotify, Button1MotionMask, \
	//	manage_mouse_moves, entities);
	mlx_hook(display->win_ptr, DestroyNotify, StructureNotifyMask, \
		terminate_minirt, entities);
	mlx_loop(display->mlx_ptr);
}
