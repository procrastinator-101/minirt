/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:46:40 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/16 17:25:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/support_functions.h"

static double	update_ret(char *str, int i, int radix, double ret)
{
	if (radix > 0)
		ret = ret + (double)(str[i] - 48) / pow(10.0, i - radix);
	else
		ret = ret * 10 + (str[i] - 48);
	return (ret);
}

double			ft_atod_length(char *str, int *len)
{
	int		i;
	int		sp;
	int		radix;
	double	ret;

	sp = 0;
	*len = 0;
	while (str[sp] == 32 || (str[sp] > 8 && str[sp] < 14))
		sp++;
	i = sp + ((str[sp] == '-' || str[sp] == '+') ? 1 : 0);
	ret = 0;
	radix = -1;
	while ((str[i] > 47 && str[i] < 58) || str[i] == '.')
	{
		if (radix > 0 && str[i] == '.')
			break ;
		if (str[i] == '.')
			radix = i;
		else
			ret = update_ret(str, i, radix, ret);
		i++;
		*len = i - sp;
	}
	return (str[sp] == '-' ? -ret : ret);
}
