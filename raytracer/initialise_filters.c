/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_filters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:22:43 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/02 08:20:17 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	initialise_filters(void **entities)
{
	t_sepia			*sepia;
	t_anti_aliasing	*anti_aliasing;

	if (!entities[SEPIA])
	{
		if (!(sepia = malloc(sizeof(t_sepia))))
			manage_exec_error(entities, EMAF);
		entities[SEPIA] = sepia;
		sepia->on = 0;
	}
	if (!entities[ANTI_ALIASING])
	{
		if (!(anti_aliasing = malloc(sizeof(t_anti_aliasing))))
			manage_exec_error(entities, EMAF);
		entities[ANTI_ALIASING] = anti_aliasing;
		anti_aliasing->factor = 1;
	}
}
