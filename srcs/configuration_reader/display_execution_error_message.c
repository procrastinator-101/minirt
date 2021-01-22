/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_execution_error_message.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:03:02 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/22 12:10:54 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

static void	display_map_file_error_message(int error_number)
{
	if (error_number == EMFME)
		ft_putstr_fd("the map file has no extension", 2);
	else if (error_number == EMFWE)
		ft_putstr_fd("the map file has a wrong extension", 2);
	else if (error_number == EMPEF)
		ft_putstr_fd("the map file extraction has failed", 2);
	else if (error_number == EMPICF)
		ft_putstr_fd("the map file image creation has failed", 2);
}

void	display_execution_error_message(int error_number)
{
	if (error_number >= EMFME && error_number <= EMPICF)
		display_map_file_error_message(error_number);
	else if (error_number >= EIFRF && error_number <= EIFCF)
		display_input_file_error_message(error_number);
	else if (error_number >= EBFOF && error_number <= EBFWF)
		display_bmp_file_error_message(error_number);
	else if (error_number >= EMCF && error_number <= EICF)
		display_mlx_error_message(error_number);
}
