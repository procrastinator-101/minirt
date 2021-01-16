/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_pyramids.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 22:52:56 by youness           #+#    #+#             */
/*   Updated: 2020/04/14 21:59:21 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

int	construct_pyramids(t_pyramid *tail, void **entities)
{
	int	ret;

	while (tail)
	{
		ret = build_pyramid(tail, entities);
		if (ret)
			return (ret);
		tail = tail->next;
	}
	return (0);
}
