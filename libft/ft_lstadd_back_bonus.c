/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:55:40 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/22 22:22:50 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *ptr;

	ptr = *alst;
	if (!*alst)
		*alst = new;
	else
	{
		while (ptr)
		{
			if (!ptr->next)
				break ;
			ptr = ptr->next;
		}
		ptr->next = new;
	}
}
