/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_filters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:22:43 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/01 10:23:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	initialise_filters(void **entities)
{
	t_sepia			*sepia;
	t_anti_aliasing	*anti_aliasing;

	if (!(sepia = malloc(sizeof(t_sepia))))
		manage_exec_error(entities, EMA);
	entities[SEPIA] = sepia;
	if (!(anti_aliasing = malloc(sizeof(t_anti_aliasing))))
		manage_exec_error(entities, EMA);
	entities[ANTI_ALIASING] = anti_aliasing;
	sepia->on = 0;
	anti_aliasing->factor = 1;
	sepia->set = 0;
	anti_aliasing->set = 0;
}
