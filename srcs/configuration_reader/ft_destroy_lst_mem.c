/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_lst_mem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:45:02 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/17 17:34:13 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

static void	destroy_triangle(t_triangle *triangle, t_display *display)
{
	if (triangle->parent)
		return ;
	if (triangle->texture.uv_map.img_ptr)
		mlx_destroy_image(display->mlx_ptr, triangle->texture.uv_map.img_ptr);
	if (triangle->texture.bump_map.img_ptr)
		mlx_destroy_image(display->mlx_ptr, triangle->texture.bump_map.img_ptr);
}

static void	destroy_square(t_square *square, t_display *display)
{
	if (square->parent)
		return ;
	if (square->texture.uv_map.img_ptr)
		mlx_destroy_image(display->mlx_ptr, square->texture.uv_map.img_ptr);
	if (square->texture.bump_map.img_ptr)
		mlx_destroy_image(display->mlx_ptr, square->texture.bump_map.img_ptr);
}

static void	destroy_skybox(t_skybox *skybox, t_display *display)
{
	int		i;
	void	*img_ptr;

	i = -1;
	while (++i < 6)
	{
		img_ptr = skybox->faces[i]->texture.uv_map.img_ptr;
		if (img_ptr)
			mlx_destroy_image(display->mlx_ptr, img_ptr);
	}
}

void		ft_destroy_lst_mem(void *lst_mem, int type, t_display *display)
{
	t_texture	*texture;

	if (type < SPHERE || type == ANTI_ALIASING || type == SEPIA)
		free(lst_mem);
	else if (type == SQUARE)
		destroy_square(lst_mem, display);
	else if (type == TRIANGLE)
		destroy_triangle(lst_mem, display);
	else if (type == SKYBOX)
		destroy_skybox(lst_mem);
	else
	{
		texture = get_lst_mem_texture(lst_mem, type);
		if (texture->uv_map.img_ptr)
			mlx_destroy_image(display->mlx_ptr, texture->uv_map.img_ptr);
		if (texture->bump_map.img_ptr)
			mlx_destroy_image(display->mlx_ptr, texture->bump_map.img_ptr);
	}
}
