/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:37:22 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/17 16:24:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

/*
 ** this is a comment
 */

#include <string.h>

char    *ft_strrstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int needle_len;
	int haystack_len;

	if (!haystack || ! needle)
		return (0);
	needle_len = strlen(needle);
	haystack_len = strlen(haystack);
	while (haystack_len >= needle_len)
	{
		i = haystack_len - 1;
		j = needle_len - 1;
		while (j >= 0 && i >= j)
		{
			if (needle[j] != haystack[i])
				break ;
			if (j == 0)
				return ((char *)(haystack + i));
			i--;
			j--;
		}
		haystack_len--;
	}
	return (0);
}

int main()
{
	char haystack[] = "123456789 .rt  .rtabcgd lldns;";
	char needle[] = "l";
	printf("ret = %s\n", ft_strrstr(haystack, needle));
	return 0;
}
