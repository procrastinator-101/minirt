/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:52:20 by youness           #+#    #+#             */
/*   Updated: 2020/12/22 10:51:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	rotate_triangle(t_triangle *triangle, t_smat_3d m)
{
	triangle->c = smat_vec_3d_product(m, triangle->c);
	triangle->p1 = smat_vec_3d_product(m, triangle->p1);
	triangle->p2 = smat_vec_3d_product(m, triangle->p2);
	triangle->p3 = smat_vec_3d_product(m, triangle->p3);
	triangle->basis.u = smat_vec_3d_product(m, triangle->basis.u);
	triangle->basis.v = smat_vec_3d_product(m, triangle->basis.v);
	triangle->basis.w = cross_product(triangle->basis.u, triangle->basis.v);
}
