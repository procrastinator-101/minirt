/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:37:22 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/19 12:02:43 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <math.h>
#include "includes/minirt.h"

/*
 ** this is a comment
 */

int ft_isnumber(char *num)
{
    int i;

    i = 0;
    if (ft_issign(num[i]))
        i++;
    if (ft_isdigit(num[i]))
        i += 2;
    return (i < 2 ? 0 : 1);
}

int main()
{
	char num[] = "5.2";
	printf("ret = %d\n", ft_isnumber(num));
	return (0);
}
