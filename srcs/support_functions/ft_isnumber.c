/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:52:51 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/31 14:15:09 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/support_functions.h"

int	ft_isnumber(char *num)
{
	int i;

	i = 0;
	if (ft_issign(num[i]))
		i++;
	if (ft_isdigit(num[i]))
		i += 2;
	return (i < 2 ? 0 : 1);
}
