/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:02:54 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/25 19:05:00 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	update_start(char *line, int start)
{
	int new_start;

	if (start == -1)
		return (-1);
	new_start = find_next_arg(line, start);
	if (new_start == start)
		return (-1);
	return (new_start);
}
