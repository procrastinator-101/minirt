/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:58:23 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 18:51:20 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	find_next_arg(char *line, int start)
{
	while ((line[start] > 7 && line[start] < 12) || line[start] == 32)
		start++;
	return (start);
}
