/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:37:44 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/02 10:08:14 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "support_functions.h"

int	ft_atoi_length(char *str, int *len)
{
	int	i;
	int	sp;
	int	ret;

	*len = 0;
	sp = 0;
	while (str[sp] == 32 || (str[sp] > 8 && str[sp] < 14))
		sp++;
	i = sp;
	if (str[sp] == '-' || str[sp] == '+')
		i++;
	ret = 0;
	while (str[i] > 47 && str[i] < 58)
		ret = ret * 10 + (str[i++] - 48);
	*len = i - sp;
	return (str[sp] == '-' ? -ret : ret);
}
