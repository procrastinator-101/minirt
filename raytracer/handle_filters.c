/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_filters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:40:33 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/27 12:52:06 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static void	update_aa_factor(void **entities, t_anti_aliasing *aa, int key)
{
	if (key == PLUS)
		aa->factor += 1;
	else if (key == MINUS)
		aa->factor -= 1;
	if (aa->factor > MAX_AA_FACTOR)
		aa->factor = MAX_AA_FACTOR;
	else if (aa->factor < 1)
		aa->factor = 1;
	entities[RENDER] = (void *)1;
}

void		handle_filters(void **entities, int key)
{
	if (key == S)
	{
		((t_sepia *)(entities[SEPIA]))->on ^= 1;
		entities[RENDER] = (void *)1;
	}
	else if (key == A)
	{
		entities[USER_OBJECT] = entities[ANTI_ALIASING];
		entities[USER_OBJECT_TYPE] = (void *)ANTI_ALIASING;
		entities[RENDER] = (void *)0;
	}
	else if (entities[USER_OBJECT_TYPE] == (void *)ANTI_ALIASING && \
		(key == MINUS || key == PLUS))
		update_aa_factor(entities, entities[ANTI_ALIASING], key);
}
