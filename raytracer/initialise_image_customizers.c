/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_image_customizers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:56:44 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/01 19:05:03 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	initialise_image_customizers(void **entities)
{
	int	*sepia;
	int	*aa_factor;

	if (!(sepia = malloc(sizeof(int))))
		return (EMA);
	entities[SEPIA] = sepia;
	if (!(aa_factor = malloc(sizeof(int))))
		return (EMA);
	entities[ANTI_ALIASING] = aa_factor;
	*sepia = 0;
	*aa_factor = 1;
	return (0);
}
