/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_filters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:22:43 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/27 12:32:04 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	initialise_filters(void **entities)
{
	t_sepia			*sepia;
	t_anti_aliasing	*anti_aliasing;

	if (!(sepia = malloc(sizeof(t_sepia))))
		return (EMA);
	entities[SEPIA] = sepia;
	if (!(anti_aliasing = malloc(sizeof(t_anti_aliasing))))
		return (EMA);
	entities[ANTI_ALIASING] = anti_aliasing;
	sepia->on = 0;
	anti_aliasing->factor = 1;
	sepia->set = 0;
	anti_aliasing->set = 0;
	return (0);
}
