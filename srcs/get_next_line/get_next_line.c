/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:44:33 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/14 12:07:42 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	**buffers;
	int			v[6];

	if (!line || BUFFER_SIZE < 0 || (v[3] = find_buffer(&buffers, fd, v)) \
			== -1)
		return (-1);
	*line = 0;
	while (1)
	{
		if (buffers[v[3]] && *line == 0)
		{
			v[5] = sh_cut(&buffers, line, v, 1);
			if (v[5] == -1 || v[5] == 1)
				return (v[5]);
		}
		if (mini_shcut(&buffers, line, v, 2) == -1)
			return (-1);
		v[5] = sh_cut(&buffers, line, v, 2);
		if (v[5] == -1 || v[5] == 1)
			return (v[5]);
		if (v[2] == 0)
			shift_back(&buffers, v[3] - 1);
		if (v[2] == 0)
			return (0);
	}
}

int		sh_cut(char ***buffers_address, char **line, int *v, int option)
{
	int r;

	if (option > 0)
	{
		if (option == 1)
			v[1] = adjust_start((*buffers_address)[v[3] - 1], v, 1);
		if (option == 2)
		{
			v[2] = read(v[4], (*buffers_address)[v[3]], BUFFER_SIZE);
			v[1] = adjust_start((*buffers_address)[v[3] - 1], v, 1);
			if (v[2] == -1)
			{
				shift_back(buffers_address, v[3] - 1);
				return (-1);
			}
			(*buffers_address)[v[3]][v[1] + v[2]] = 0;
		}
		v[0] = ft_ccpy(line, &(*buffers_address)[v[3]], BUFFER_SIZE, v);
		start_stdin(buffers_address, v);
		v[1] = adjust_start((*buffers_address)[v[3] - 1], v, 0);
		r = mini_shcut(buffers_address, line, v, 1);
		if (r == 1 || r == -1)
			return (r);
	}
	return (0);
}

int		mini_shcut(char ***buffers_address, char **line, int *v, int option)
{
	if (option == 1)
	{
		if (v[0] == -1)
		{
			shift_back(buffers_address, v[3] - 1);
			return (-1);
		}
		if ((*line) && (*line)[v[0] - 2] == '\n')
		{
			(*line)[v[0] - 2] = 0;
			return (1);
		}
	}
	else
	{
		if (!(*buffers_address)[v[3]] && !((*buffers_address)[v[3]] = \
					malloc((BUFFER_SIZE + 1) * sizeof(char))))
		{
			shift_back(buffers_address, v[3] - 1);
			return (-1);
		}
	}
	return (0);
}

void	ft_fast_cpy(char *dest, char *src, int size)
{
	long long	*holder;
	long long	*holder2;
	int			i;

	i = sizeof(long long);
	holder = (long long *)dest;
	holder2 = (long long *)src;
	while (i <= size)
	{
		*holder = *holder2;
		i += sizeof(long long);
		holder = (i <= size ? holder + 1 : holder);
		holder2 = (i <= size ? holder2 + 1 : holder2);
	}
	i -= sizeof(long long) + 1;
	while (++i < size)
		dest[i] = src[i];
}

void	start_stdin(char ***buffers_address, int *v)
{
	if (v[2] > 0 && v[2] <= v[1] && v[2] < BUFFER_SIZE)
	{
		free((*buffers_address)[v[3]]);
		(*buffers_address)[v[3]] = 0;
		v[1] = 0;
	}
}
