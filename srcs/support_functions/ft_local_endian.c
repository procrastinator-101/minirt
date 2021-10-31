/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_local_endian.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:36:47 by youness           #+#    #+#             */
/*   Updated: 2021/01/16 18:59:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/support_functions.h"

int	ft_local_endian(void)
{
	unsigned		temp;
	unsigned char	*ptr;

	temp = 1;
	ptr = (unsigned char *)(&temp);
	return (*ptr);
}
