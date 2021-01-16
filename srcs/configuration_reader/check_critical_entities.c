/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_critical_entities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:24:12 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/10 15:30:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

int	check_critical_entities(void **entities)
{
	if (!entities[RESOLUTION])
		return (EERP);
	if (!entities[AMBIENT])
		return (EEAP);
	if (!entities[CAMERA])
		return (EECP);
	return (0);
}
