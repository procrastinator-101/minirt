/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:53:55 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/18 20:13:26 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	ft_dclst_destroy(void **tail, int type)
{
	void	*temp;
	void	*previous;

	if (!tail || !(*tail))
		return ;
	temp = get_previous_lst_mem(*tail, type);
	while (temp != *tail)
	{
		previous = get_previous_lst_mem(temp, type);
		free(temp);
		temp = previous;
	}
	free(*tail);
	*tail = 0;
}
