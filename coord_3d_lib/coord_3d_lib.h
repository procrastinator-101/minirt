/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_3d_lib.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:57:38 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/07 17:14:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD_3D_LIB_H
# define COORD_3D_LIB_H

typedef struct	s_coord_3d
{
	double		x;
	double		y;
	double		z;
}				t_coord_3d;

double			dot_product(coord_3d a, coord_3d b);
t_coord_3d		cross_product(t_coord_3d a, t_coord_3d b);
t_coord_3d		scalar_product(t_coord_3d v, double scalar);
t_coord_3d		minus_coord_3d(t_coord_3d a, t_coord_3d b);
t_coord_3d		plus_coord_3d(t_coord_3d a, t_coord_3d b);

void			normalise_3d_vec(t_coord_3d *v);
void			get_base_3d(t_coord_3d *w, t_coord_3d *v, t_coord_3d *u);

#endif
