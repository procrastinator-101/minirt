/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error_message.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:59:09 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/22 12:41:59 by yarroubi         ###   ########.fr       */
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

static void	critical_entities_message(int error_number)
{
	if (error_number == EERP)
		ft_putstr_fd("no resolution configuration has been declared", 2);
	else if (error_number == EEAP)
		ft_putstr_fd("no ambient light configuartion has been declared", 2);
	else if (error_number == EECP)
		ft_putstr_fd("no camera configuartion has been declared", 2);
}

static void	threads_error_message(int error_number)
{
	if (error_number == ETCF)
		ft_putstr_fd("the creation of some thread has failed", 2);
	else if (error_number == ETJF)
		ft_putstr_fd("the joining of some thread has failed", 2);
}

void		display_error_message(int error_number)
{
	ft_putstr_fd("Error\n", 2);
	if (error_number >= EMIFE && error_number <= EIA)
		program_arguments_error_message(error_number);
	else if (error_number >= EERP && error_number <= EECP)
		critical_entities_message(error_number);
	else if (error_number >= RESOLUTION && error_number <= EMAAD)
		display_configuration_error_message(error_number);
	else if (error_number >= EMFME && error_number <= EICF)
		display_execution_error_message(error_number);
	else if (error_number >= ETCF && error_number <= ETJF)
		threads_error_message(error_number);
	else if (error_number == EMAF)
		ft_putstr_fd("the allocation of some block of memory has failed", 2);
	else if (error_number == EUED)
		ft_putstr_fd("unknown entity has been declared", 2);
	ft_putstr_fd("\n", 2);
}
