/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_entity_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:32:42 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/01 12:51:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int	check_end_entity_info(char *line, int start, int ret)
{
	if (start == -1 || line[start])
		return (-ret);
	return (ret);
}
