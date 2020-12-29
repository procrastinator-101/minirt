/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error_message.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:59:09 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/29 11:56:58 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	execution_error_message(int error_number)
{
	if (error_number == EFR)
		ft_putstr_fd("unsuccesful file reading", 2);
	else if (error_number == EMAF)
		ft_putstr_fd("a memory allocation for some block has failed", 2);
	else if (error_number == EMC)
		ft_putstr_fd("the connection with the X server has failed", 2);
	else if (error_number == EWC)
		ft_putstr_fd("the window creation has failed", 2);
	else if (error_number == EIC)
		ft_putstr_fd("the image creation has failed", 2);
}

static void	program_arguments_error_message(int error_number)
{

}

void		display_error_message(int error_number)
{
	if (error_number >= EFR && error_number <= EIC)
		execution_error_message(error_number);
	else if (error_number >= EMFE && error_number <= EIA)
		program_arguments_error_message(error_number);
	else
		display_error_message_utils(error_number);
	printf("error number : %d\n", error_number);//
	write(2, "\n", 1);
}
