/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_cubes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:24:12 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/10 15:30:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

int	construct_cubes(t_cube *tail, void **entities)
{
	int	ret;

	while (tail)
	{
		ret = build_cube(tail, entities);
		if (ret)
			return (ret);
		tail = tail->next;
	}
	return (0);
}
