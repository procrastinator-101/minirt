/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:12:39 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 16:41:10 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	ft_lst_destroy(void **lst_tail, int type)
{
	void *tail;

	if (lst_tail && *lst_tail)
	{
		tail = choose_entity_type(*lst_tail, type);
		if (tail)
			ft_lst_destroy(&tail, type);
		if (!tail)
			ft_lst_delete(lst_tail);
	}
}
