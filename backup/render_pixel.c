/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:56:47 by yarroubi          #+#    #+#             */
/*   Updated: 2020/10/28 12:59:33 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_coord_3d	get_first_grid_center(t_coord_3d c, t_screen screen, int nb)
{
	double	tmp;

	tmp = (1.0 / nb - 1.0) / 2.0;
	c = coord_3d_plus(c, scalar_product(screen.u, screen.width * tmp));
	c = coord_3d_minus(c, scalar_product(screen.v, screen.height * tmp));
	return (c);
}

int			check_aliasing(void **entities, t_ray ray, t_rgb *rgb, \
			double jump[2])
{
	int			i;
	double		dm[4][2];
	t_rgb		tmp;
	t_screen	screen;
	t_coord_3d	p[2];

	p[0] = ray.direction;
	printf("left = ");
	print_coord_3d(p[0]);
	screen = ((t_camera *)entities[USER_CAMERA])->screen;
	i = -1;
	while (++i < 4)
	{
		dm[i][0] = i < 2 ? 0 : jump[0];
		dm[i][1] = i % 2 ? jump[1] : 0;
		//printf("dim[%d][0] = %f || dim[%d][1] = %f\n", i, dm[i][0], i, dm[i][1]);
	}
	while (i--)
	{
		p[1] = coord_3d_plus(p[0], scalar_product(screen.u, dm[i][0]));
		p[1] = coord_3d_minus(p[1], scalar_product(screen.v, dm[i][1]));
		printf("dir%d", i);
		print_coord_3d(p[1]);
		ray.direction = coord_3d_minus(p[1], ray.origin);
		tmp = get_color(ray, entities);
		*rgb = rgb_sum(*rgb, tmp);
	}
	*rgb = rgb_mul_double(*rgb, 1 / 4.0);
	return (rgb_cmp(*rgb, tmp, 1.0 / 255.0));
}

t_rgb		super_sample(void **entities, t_ray ray, t_rgb *rgb, \
			double dm[2])
{
	int			nb;
	int			end;
	int			idx[2];
	t_screen	screen;
	t_coord_3d	p[3];

	p[0] = ray.direction;
	nb = *((int *)entities[ANTI_ALIASING]);
	screen = ((t_camera *)entities[USER_CAMERA])->screen;
	idx[0] = -1;
	while (++idx[0] < nb)
	{
		p[1] = coord_3d_minus(p[0], scalar_product(screen.v, idx[0] * dm[1]));
		idx[1] = idx[0] == 0 || idx[0] == nb - 1 ? 0 : -1;
		end = idx[0] == 0 || idx[0] == nb - 1 ? nb - 1 : nb;
		while (++idx[1] < end)
		{
			p[2] = coord_3d_plus(p[1], scalar_product(screen.u, \
				idx[1] * dm[0]));
			print_coord_3d(p[2]);
			ray.direction = coord_3d_minus(p[2], ray.origin);
			*rgb = rgb_sum(*rgb, get_color(ray, entities));
		}
	}
	return (rgb_mul_double(*rgb, 1.0 / (nb * nb)));
}

int			render_pixel(void **entities, t_camera *camera, \
			t_display *display, t_ray ray)
{
	int			nb;
	double		dm[2];
	double		jump[2];
	t_rgb		rgb;
	t_coord_3d	start;

	printf("ray ");
	print_coord_3d(ray.origin);
	print_coord_3d(ray.direction);
	rgb = get_black_rgb();
	nb = *((int *)entities[ANTI_ALIASING]);
	if (nb < 2)
	{
		ray.direction = coord_3d_minus(ray.direction, ray.origin);
		rgb = get_color(ray, entities);
	}
	else
	{
		dm[0] = camera->screen.width / nb;
		dm[1] = camera->screen.height / nb;
		//printf("dm0 = %f dm1 = %f\n", dm[0], dm[1]);
		jump[0] = dm[0] * (nb - 1);
		jump[1] = dm[1] * (nb - 1);
		//printf("jm0 = %f jm1 = %f\n", jump[0], jump[1]);
		start = get_first_grid_center(ray.direction, camera->screen, nb);
		printf("start ");
		print_coord_3d(start);
		ray.direction = start;
		if (check_aliasing(entities, ray, &rgb, jump))
			rgb = super_sample(entities, ray, &rgb, dm);
	}
	return (rgb_to_int(rgb, display->server_endian));
}
