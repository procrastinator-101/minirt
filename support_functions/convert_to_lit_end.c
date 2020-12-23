/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_lit_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:26:38 by youness           #+#    #+#             */
/*   Updated: 2020/12/23 12:25:54 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "support_functions.h"

void    convert_to_lit_end(char *dest, unsigned num, int size)
{
	int i;

	i = -1;
	while (++i < size)
		dest[i] = num >> (i * 8);
}
