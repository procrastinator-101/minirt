/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 19:50:50 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/18 11:36:22 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

int	get_cube(char *line, void **entities)
{
	int		start;
	t_cube	*cube;

	if (!(cube = malloc(sizeof(t_cube))))
		return (-EMAF);
	ft_lst_add_head(entities + CUBE, cube, CUBE);
	cube->texture.uv_map.img_ptr = 0;
	cube->texture.bump_map.img_ptr = 0;
	if ((start = update_start(line, 2)) == -1)
		return (-CUBE);
	start = fetch_point_3d(line, &(cube->center), start);
	if ((start = update_start(line, start)) == -1)
		return (-CUBE);
	start = fetch_vector_3d(line, &(cube->basis.w), start);
	if ((start = update_start(line, start)) == -1)
		return (-CUBE);
	get_base_3d(&(cube->basis.w), &(cube->basis.v), &(cube->basis.u));
	start = get_radius(line, &(cube->radius), start);
	if (start == -1)
		return (-CUBE);
	cube->texture.width = cube->radius * 2.0;
	cube->texture.height = cube->radius * 2.0;
	initialise_map_dimension(&(cube->texture));
	return (get_texture(line + start, &(cube->texture), entities[DISPLAY], \
		CUBE));
}
