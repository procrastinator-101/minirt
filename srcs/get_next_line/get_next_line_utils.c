/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:59:24 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/14 12:09:13 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

int	adjust_start(char *buffer_fd, int *v, int option)
{
	char	*str;
	int		i;

	if (option)
	{
		str = (char *)(&(v[1]));
		i = 1;
		while (++i < (int)sizeof(int) + 2)
			str[i - 2] = buffer_fd[i];
	}
	else
	{
		str = (char *)(&(v[1]));
		i = 1;
		while (++i < (int)sizeof(int) + 2)
			buffer_fd[i] = (v[1] >= BUFFER_SIZE ? 0 : str[i - 2]);
	}
	return (v[1] >= BUFFER_SIZE ? 0 : v[1]);
}

int	find_buffer(char ***buffers_address, int fd, int *v)
{
	int		i;
	int		p;
	char	*str;
	char	**buffers;

	buffers = *buffers_address;
	i = -1;
	while (++i < 3)
		v[i] = 0;
	v[4] = fd;
	i = 0;
	p = 0;
	str = (char *)(&p);
	if (!buffers)
		return (resize_buffers(buffers_address, 0, fd));
	while (buffers[i])
	{
		str[0] = buffers[i][0];
		str[1] = buffers[i][1];
		v[1] = (fd == p ? adjust_start(buffers[i], v, 1) : 0);
		if (fd == p)
			return (i + 1);
		i += 2;
	}
	return (resize_buffers(buffers_address, i, fd));
}

int	resize_buffers(char ***buffers_address, int buffers_len, int fd)
{
	char	**ptr;
	int		i;

	if (!(ptr = malloc((buffers_len + 3) * sizeof(char *))))
		return (-1);
	i = -1;
	ptr[buffers_len + 2] = 0;
	ptr[buffers_len + 1] = 0;
	while (++i < buffers_len)
		ptr[i] = (*buffers_address)[i];
	free(*buffers_address);
	if (!(ptr[buffers_len] = malloc((2 + sizeof(int)) * sizeof(char))))
	{
		shift_back(&ptr, buffers_len);
		return (-1);
	}
	ptr[buffers_len][0] = fd;
	ptr[buffers_len][1] = fd >> 8;
	i = 1;
	while (++i < (int)sizeof(int) + 2)
		ptr[buffers_len][i] = 0;
	*buffers_address = ptr;
	return (buffers_len + 1);
}

int	shift_back(char ***buffers_address, int index)
{
	char	**ptr;
	int		size;

	size = 0;
	while ((*buffers_address)[size])
		size += 2;
	size++;
	free((*buffers_address)[index]);
	free((*buffers_address)[index + 1]);
	if (size <= 3)
	{
		free(*buffers_address);
		*buffers_address = NULL;
		return (1);
	}
	while (index++ < size - 2)
		(*buffers_address)[index - 1] = (*buffers_address)[index + 1];
	if (!(ptr = malloc((size - 2) * sizeof(char *))))
		return (-1);
	index = -1;
	while (++index < size - 2)
		ptr[index] = (*buffers_address)[index];
	free(*buffers_address);
	*buffers_address = ptr;
	return (1);
}

int	ft_ccpy(char **line, char **buffer_address, int buffer_size, int *v)
{
	int		i;
	int		j;
	char	*ptr;
	char	*buffer;

	buffer = *buffer_address;
	i = v[1];
	while (i < buffer_size && buffer[i] && buffer[i] != '\n')
		i++;
	i += (buffer[i] == '\n');
	if (!(ptr = malloc((v[0] + i - v[1] + (v[0] == 0)\
						* sizeof(char)))))
		return (-1);
	ft_fast_cpy(ptr, *line, v[0]);
	free(*line);
	ft_fast_cpy(ptr + v[0] - (v[0] > 0), buffer + v[1], i - v[1]);
	ptr[i - v[1] + v[0] - (v[0] > 0)] = 0;
	*line = ptr;
	j = v[1];
	v[1] = i;
	if (i >= buffer_size)
		free(*buffer_address);
	if (i >= buffer_size)
		*buffer_address = 0;
	return (i - j + v[0] + (v[0] == 0));
}
