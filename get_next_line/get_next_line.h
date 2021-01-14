/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:45:04 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/14 12:07:34 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 100

int		get_next_line(int fd, char **line);

int		find_buffer(char ***buffers_address, int fd, int *v);
int		resize_buffers(char ***buffers_address, int buffers_len, int fd);
int		shift_back(char ***buffers_address, int index);

int		sh_cut(char ***buffers_address, char **line, int *v, int option);
int		mini_shcut(char ***buffers_address, char **line, int *v, int option);

int		ft_ccpy(char **line, char **buffer_address, int buffer_size, int *v);
void	ft_fast_cpy(char *dest, char *src, int size);

void	start_stdin(char ***buffers_address, int *v);
int		adjust_start(char *buffer_fd, int *v, int option);

#endif
