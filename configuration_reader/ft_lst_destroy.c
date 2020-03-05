/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:12:39 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/05 18:09:47 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	ft_lst_destroy(void **lst_tail, int type)
{
	void	*tail;
	void	*next;

	if (lst_tail && *lst_tail)
	{
		tail = choose_entity_type(*lst_tail, type);
		while (tail != *lst_tail)
		{
			next = choose_entity_type(tail, type);
			ft_lst_delete(&tail);
			tail = next;
		}
		ft_lst_delete(lst_tail);
		*lst_tail = 0;
	}
}
