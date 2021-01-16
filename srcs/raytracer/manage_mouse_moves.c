/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mouse_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:23:07 by youness           #+#    #+#             */
/*   Updated: 2020/11/01 20:22:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	manage_mouse_moves(int x, int y, void *param)
{
	if (param && y && x)
		x = -x * (-1);
	printf("x = %d y = %d\n", x, y);
	return (0);
}
