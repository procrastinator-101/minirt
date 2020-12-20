/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:51:15 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/21 15:20:02 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power(int p)
{
	int r;

	r = 1;
	while (p > 0)
	{
		r *= 10;
		p--;
	}
	return (r);
}

int			ft_atoi(const char *str)
{
	int sp;
	int i;
	int sign;
	int last;

	i = 0;
	sp = 0;
	while (str[sp] == 32 || (str[sp] > 8 && str[sp] < 14))
		sp++;
	sign = (str[sp] == 45 ? -1 : 0);
	sign = (str[sp] == 43 && sign != -1 ? 1 : sign);
	last = (sign < 0 ? sp - sign : sp + sign);
	sp = last - 1;
	while (str[last] > 47 && str[last] < 58)
		last++;
	while (++sp < last)
		i -= (str[sp] - 48) * power(last - sp - 1);
	return (sign < 0 ? i : -i);
}
