/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 21:16:54 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/04 11:34:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	update_cube_faces(t_cube *cube, int index)
{
	cube->faces[index]->texture = cube->texture;
	if (cube->texture.type[0] == CHECKERBOARD)
	{
		if ((index / 2) % 2)
		{
			cube->faces[index]->texture.rgb1 = cube->texture.rgb2;
			cube->faces[index]->texture.rgb2 = cube->texture.rgb1;
		}
		else
		{
			cube->faces[index]->texture.rgb1 = cube->texture.rgb1;
			cube->faces[index]->texture.rgb2 = cube->texture.rgb2;
		}
	}
	cube->faces[index]->radius = cube->radius;
	cube->faces[index]->parent = cube;
	cube->faces[index]->parent_type = CUBE;
}

int			build_cube(t_cube *cube, void **entities)
{
	int			i;
	t_coord_3d	base[3];

	i = -1;
	while (++i < 6)
	{
		if (!(cube->faces[i] = malloc(sizeof(t_square))))
			return (EMA);
		ft_lst_add_head(entities + SQUARE, cube->faces[i], SQUARE);
		update_cube_faces(cube, i);
	}
	base[0] = cube->basis.w;
	base[1] = cube->basis.v;
	base[2] = cube->basis.u;
	build_cube_faces(cube->faces, cube->center, cube->radius, base);
	return (0);
}
