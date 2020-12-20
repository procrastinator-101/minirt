/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:27:58 by yarroubi          #+#    #+#             */
/*   Updated: 2020/06/22 15:10:48 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	ft_lst_destroy(void **lst_tail, int type)
{
	void	*tail;
	void	*next;

	if (!lst_tail || !(*lst_tail))
		return ;
	tail = *lst_tail;
	while (tail)
	{
		next = get_next_lst_mem(tail, type);
		free(tail);
		tail = next;
	}
	*lst_tail = 0;
}
