/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_3d_lib.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:57:38 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 20:57:27 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD_3D_LIB_H
# define COORD_3D_LIB_H

# include <math.h>

typedef struct	s_coord_3d
{
	double		x;
	double		y;
	double		z;
}				t_coord_3d;

double			dot_product(t_coord_3d a, t_coord_3d b);
t_coord_3d		cross_product(t_coord_3d a, t_coord_3d b);
t_coord_3d		scalar_product(t_coord_3d v, double scalar);

int				coord_3d_cmp(t_coord_3d a, t_coord_3d b);
t_coord_3d		coord_3d_minus(t_coord_3d a, t_coord_3d b);
t_coord_3d		coord_3d_plus(t_coord_3d a, t_coord_3d b);


void			normalise_3d_vec(t_coord_3d *v);
void			get_base_3d(t_coord_3d *w, t_coord_3d *v, t_coord_3d *u);

#endif
