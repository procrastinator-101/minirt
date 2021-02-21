/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prog_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:00:45 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/02 08:05:45 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	check_file_extension(char **argv)
{
	char	*tmp;

	if (!(tmp = ft_strrchr(argv[1], '.')))
	{
		display_error_message(EMIFE);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(tmp + 1, "rt"))
	{
		display_error_message(EWIFE);
		exit(EXIT_FAILURE);
	}
}

void		check_prog_arg(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		if (argc < 2)
			display_error_message(EMIF);
		else
			display_error_message(ETCPA);
		exit(EXIT_FAILURE);
	}
	if (argc == 3)
	{
		if (ft_strcmp("--save", argv[2]))
		{
			display_error_message(EIA);
			exit(EXIT_FAILURE);
		}
	}
	check_file_extension(argv);
}
