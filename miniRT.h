/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:07:18 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 17:20:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "coord_3d_lib/coord_3d_lib.h"
# include "configuration_reader/configuration_reader.h"

# define FILE_READING_ERROR					11
# define MEMORY_ALLOCATION_FAILURE			12
# define MLX_CONNECTION_ERROR				13
# define WINDOW_CREATION_ERROR				14
# define IMAGE_CREATION_ERROR				15

typedef struct	s_display
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_addr;
	int			endian;
}				t_display;

int				ft_atoi_length(char *str, int *len);
double			ft_atod_length(char *str, int *len);

double			ft_min(double a, double b);

#endif
