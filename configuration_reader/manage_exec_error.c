/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_exec_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:24:12 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/10 15:30:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	manage_exec_error(void **entities, int error_number)
{
	destroy_entities(entities);
	display_error_message(error_number);
	exit(EXIT_FAILURE);
}
