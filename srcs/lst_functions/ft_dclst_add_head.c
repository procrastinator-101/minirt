/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_add_head.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:38:48 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/14 09:48:22 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	ft_dclst_add_head(void **lst_tail, void *new, int type)
{
	void	*tail;
	void	*next;

	if (!lst_tail || !new)
		return ;
	if (!(*lst_tail))
		*lst_tail = new;
	else
	{
		tail = *lst_tail;
		next = get_next_lst_mem(tail, type);
		while (next != *lst_tail)
		{
			tail = next;
			next = get_next_lst_mem(tail, type);
		}
		ft_update_next(tail, new, type);
		ft_update_previous(new, tail, type);
	}
	ft_update_next(new, *lst_tail, type);
	ft_update_previous(*lst_tail, new, type);
}
