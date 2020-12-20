/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:14:00 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/20 18:33:26 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *before_new;
	t_list *head;

	before_new = lst;
	while (lst)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
		{
			ft_lstclear((before_new == lst ? &new : &head), del);
			return (0);
		}
		new->content = f(lst->content);
		new->next = 0;
		if (before_new == lst)
			head = new;
		else
			ft_lstadd_back(&before_new, new);
		lst = lst->next;
		before_new = new;
	}
	return (before_new == lst ? 0 : head);
}
