/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltb_endian.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:31:19 by youness           #+#    #+#             */
/*   Updated: 2020/09/30 16:28:24 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_btl_endian(unsigned char *dst, unsigned char *src, int offsets, int size)
{
	unsigned char	l;
	unsigned char	b;
	unsigned char	*ptr;
	unsigned char	lr[2];
	unsigned char	br[2];
	unsigned char	temp[4];

	ptr = (unsigned char *)temp;
	if (dst == src)
	{
		ft_memcpy(temp, src, size / 8 + (size % 8 ? 1 : 0));

	else
		ptr = src;
	br[0] = 8 - (offsets & 0xff);
	br[1] = size < br[0] ? br[0] - size : 1;
	lr[0] = 8 - (offsets & 0xff00);
	lr[1] = size < lr[0] ? lr[0] - size : 1;
	i = size / 8 - !(size % 8);
	while(size > 0)
	{
		*src = dst[i] << (l - b);
		size -= l < b ? l : b;
		temp = l;
		l = l > b ? l - b : 8;
		b = b > temp ? b - temp : 8;
		src += l == 8;
		i -= b == 8;
	}
}
