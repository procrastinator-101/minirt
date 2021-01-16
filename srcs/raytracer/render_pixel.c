/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:56:47 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/31 19:24:03 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_coord_3d	get_first_grid_center(t_coord_3d c, t_camera *camera)
{
	t_coord_3d	v1;
	t_coord_3d	v2;

	v1 = coord_3d_add(camera->pixel.v, camera->sub_pixel.u);
	v2 = coord_3d_add(camera->pixel.u, camera->sub_pixel.v);
	v1 = coord_3d_sub(v1, v2);
	return (coord_3d_add(c, scalar_product(v1, 0.5)));
}

t_rgb		adaptive_sample(void **entities, t_camera *camera, t_ray ray, \
			int nb)
{
	int			i;
	int			j;
	int			inc;
	t_rgb		rgb;
	t_coord_3d	p[2];

	p[0] = ray.direction;
	rgb = get_black_rgb();
	i = -1;
	while (++i < nb)
	{
		p[1] = p[0];
		inc = i == 0 || i == nb - 1 ? 1 : nb - 1;
		j = 0;
		while (j < nb)
		{
			ray.direction = coord_3d_sub(p[1], ray.origin);
			rgb = rgb_sum(rgb, get_color(ray, entities));
			j += inc;
			p[1] = coord_3d_add(p[0], scalar_product(camera->sub_pixel.u, j));
		}
		p[0] = coord_3d_sub(p[0], camera->sub_pixel.v);
	}
	return (rgb);
}

t_rgb		super_sample(void **entities, t_camera *camera, t_ray ray, int nb)
{
	int			i;
	int			j;
	t_rgb		rgb;
	t_coord_3d	p[2];

	p[0] = ray.direction;
	rgb = get_black_rgb();
	i = 0;
	while (++i < nb - 1)
	{
		p[1] = p[0];
		j = 0;
		while (++j < nb - 1)
		{
			ray.direction = coord_3d_sub(p[1], ray.origin);
			rgb = rgb_sum(rgb, get_color(ray, entities));
			p[1] = coord_3d_add(p[1], camera->sub_pixel.u);
		}
		p[0] = coord_3d_sub(p[0], camera->sub_pixel.v);
	}
	return (rgb);
}

unsigned	render_pixel(void **entities, t_camera *camera, t_ray ray)
{
	int			nb;
	t_rgb		rgb;
	t_rgb		tmp;
	t_coord_3d	start;

	nb = *((int *)entities[ANTI_ALIASING]);
	start = get_first_grid_center(ray.direction, camera);
	ray.direction = coord_3d_sub(ray.direction, ray.origin);
	rgb = get_color(ray, entities);
	if (nb > 1)
	{
		ray.direction = start;
		tmp = adaptive_sample(entities, camera, ray, nb);
		if (rgb_cmp(rgb, rgb_mul_double(tmp, 1 / 4.0), 1.0 / 255.0))
		{
			rgb = rgb_sum(rgb, super_sample(entities, camera, ray, nb));
			rgb = rgb_mul_double(rgb_sum(rgb, tmp), 1.0 / (nb * nb + 1));
		}
		else
			rgb = rgb_mul_double(rgb_sum(rgb, tmp), 1.0 / (4 * nb - 3));
	}
	return (rgb_to_uint(rgb));
}
