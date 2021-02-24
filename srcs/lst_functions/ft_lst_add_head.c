/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:45:33 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/16 18:57:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	ft_lst_add_head(void **lst_tail, void *new, int type)
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
		while (next)
		{
			tail = next;
			next = get_next_lst_mem(tail, type);
		}
		ft_update_next(tail, new, type);
	}
	ft_update_next(new, NULL, type);
}
