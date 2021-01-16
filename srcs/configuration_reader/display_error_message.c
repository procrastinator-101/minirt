/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error_message.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:59:09 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/16 17:15:15 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

static void	program_arguments_error_message(int error_number)
{
	if (error_number == EMIFE)
		ft_putstr_fd("the input file has no extension", 2);
	else if (error_number == EWIFE)
		ft_putstr_fd("the input file has a wrong extension", 2);
	else if (error_number == EMIF)
		ft_putstr_fd("no input file has been submitted", 2);
	else if (error_number == ETCPA)
		ft_putstr_fd("the program accepts 2 arguments at max", 2);
	else if (error_number == EIA)
		ft_putstr_fd("invalid argument", 2);
}

static void	execution_error_message(int error_number)
{
	if (error_number == EIFRF)
		ft_putstr_fd("the file reading process failed", 2);
	else if (error_number == EMAF)
		ft_putstr_fd("a memory allocation for some block has failed", 2);
	else if (error_number == EMCF)
		ft_putstr_fd("the connection with the X server has failed", 2);
	else if (error_number == EWCF)
		ft_putstr_fd("the window creation has failed", 2);
	else if (error_number == EICF)
		ft_putstr_fd("the image creation failed", 2);
}

static void	critical_entities_message(int error_number)
{
	if (error_number == EERP)
		ft_putstr_fd("no resolution configuration has been declared", 2);
	else if (error_number == EEAP)
		ft_putstr_fd("no ambient light configuartion has been declared", 2);
	else if (error_number == EECP)
		ft_putstr_fd("no camera configuartion has been declared", 2);
}

void		display_error_message(int error_number)
{
	ft_putstr_fd("Error\n", 2);
	if (error_number >= EMIFE && error_number <= EIA)
		program_arguments_error_message(error_number);
	else if (error_number >= EIFRF && error_number <= EICF)
		execution_error_message(error_number);
	else if (error_number >= EERP && error_number <= EECP)
		critical_entities_message(error_number);
	else
		display_error_message_utils(error_number);
	ft_putstr_fd("\n", 2);
}
