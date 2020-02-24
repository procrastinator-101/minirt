/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:06:21 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/20 18:39:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (*lst)
	{
		if ((*lst)->next)
			ft_lstclear(&((*lst)->next), del);
		if (!(*lst)->next)
		{
			del((*lst)->content);
			free(*lst);
		}
		*lst = 0;
	}
}
