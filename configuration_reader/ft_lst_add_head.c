/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:45:33 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/18 19:36:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_lst_add_head(void **lst_tail, void *new, int type)
{
	void	*tail;
	void	*next;

	tail = new;
	if (!(*lst_tail))
		*lst_tail = tail;
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
