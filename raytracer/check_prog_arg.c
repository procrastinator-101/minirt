/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prog_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:00:45 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/23 17:08:01 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static void	check_file_extension(char **argv, int file_index)
{
	char	*tmp;

	if (!(tmp = ft_strrchr(argv[file_index], '.')))
	{
		display_error_message(EMFE);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(tmp + 1, "rt"))
	{
		display_error_message(EWFE);
		exit(EXIT_FAILURE);
	}
}

void		check_prog_arg(int argc, char **argv, int *file_index)
{
	if (argc < 2 || argc > 3)
	{
		if (argc < 2)
			display_error_message(EMIF);
		else
			display_error_message(EUPA);
		exit(EXIT_FAILURE);
	}
	if (argc == 3)
	{
		*file_index = 2;
		if (ft_strcmp("--save", argv[1]))
		{
			display_error_message(EIA);
			exit(EXIT_FAILURE);
		}
		check_file_extension(argv, *file_index);
		return ;
	}
	*file_index = 1;
	check_file_extension(argv, *file_index);
}
