/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:07:18 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/23 21:44:51 by yarroubi         ###   ########.fr       */
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
# include "configuration_reader/configuration_reader.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_ray
{
	t_point		origin;
	t_point		direction;
}				t_ray;

typedef struct	s_sphere
{
	t_point		center;
	double		radius;
}				t_sphere;

typedef struct	s_resolution
{
	int			width;
	int			height;
}				t_resolution;

typedef struct	s_ambient
{
	double		ratio;
	int			red;
	int			green;
	int			blue;
}				t_ambient;

#endif
