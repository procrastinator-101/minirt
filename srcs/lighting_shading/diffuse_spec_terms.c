/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_spec_terms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:33:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/04/14 23:19:07 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	diffuse_spec_terms(t_ray l, t_coord_3d n, t_coord_3d v, t_light *light)
{
	double		temp;
	double		distance;
	double		phong_ratio;
	t_rgb		rgb;
	t_coord_3d	r;

	distance = coord_3d_len(l.direction);
	normalise_3d_vec(&(l.direction));
	normalise_3d_vec(&v);
	v = scalar_product(v, -1);
	temp = dot_product(n, l.direction);
	phong_ratio = ft_max(0, temp);
	r = coord_3d_sub(scalar_product(n, 2 * temp), l.direction);
	normalise_3d_vec(&r);
	phong_ratio += ft_max(0, dot_product(r, v));
	rgb = rgb_mul_double(light->rgb, light->brightness / (distance * distance));
	rgb = rgb_mul_double(light->rgb, phong_ratio);
	return (rgb);
}
