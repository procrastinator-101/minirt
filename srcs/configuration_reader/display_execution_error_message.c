/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_execution_error_message.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:03:02 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/22 18:49:26 by yarroubi         ###   ########.fr       */
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

static void	display_input_file_error_message(int error_number)
{
	if (error_number == EIFOF)
		ft_putstr_fd("the input file opening process has failed", 2);
	else if (error_number == EIFRE)
		ft_putstr_fd("the input file reading process has failed", 2);
	else if (error_number == EIFCF)
		ft_putstr_fd("the input file closing process has failed", 2);
}

static void	display_bmp_file_error_message(int error_number)
{
	if (error_number == EBFOF)
		ft_putstr_fd("the bmp file opening process has failed", 2);
	else if (error_number == EBFCF)
		ft_putstr_fd("the bmp file closing process has failed", 2);
	else if (error_number == EBFWF)
		ft_putstr_fd("the bmp file writing process has falied", 2);
}

static void	display_mlx_error_message(int error_number)
{
	if (error_number == EMCF)
		ft_putstr_fd("the mlx connection with the X server has failed", 2);
	else if (error_number == EWCF)
		ft_putstr_fd("the mlx window creation has failed", 2);
	else if (error_number == EICF)
		ft_putstr_fd("the mlx image creation had failed", 2);
	else if (error_number == EIEF)
		ft_putstr_fd("the mlx image extraction had failed", 2);
}

void		display_execution_error_message(int error_number)
{
	if (error_number >= EMFME && error_number <= EMPICF)
		display_map_file_error_message(error_number);
	else if (error_number >= EIFOF && error_number <= EIFCF)
		display_input_file_error_message(error_number);
	else if (error_number >= EBFOF && error_number <= EBFWF)
		display_bmp_file_error_message(error_number);
	else if (error_number >= EMCF && error_number <= EIEF)
		display_mlx_error_message(error_number);
}
