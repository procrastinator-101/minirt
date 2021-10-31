/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:27:58 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/17 17:45:00 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	ft_lst_destroy(void **lst_tail, int type, t_display *display)
{
	void	*tail;
	void	*next;

	if (!lst_tail || !(*lst_tail))
		return ;
	tail = *lst_tail;
	while (tail)
	{
		next = get_next_lst_mem(tail, type);
		ft_destroy_lst_mem(tail, type, display);
		tail = next;
	}
	*lst_tail = 0;
}
