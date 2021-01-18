/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_skybox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 08:35:41 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/18 11:41:01 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

static void	get_skybox_faces_basis(t_square *faces)
{
	int			i;
	t_coord_3d	v[3];

	v[0] = get_coord_3d(1, 0, 0);
	v[1] = get_coord_3d(0, 1, 0);
	v[2] = get_coord_3d(0, 0, 1);
	i = -1;
	while (++i < 6)
	{
		if (i % 2 == 0)
			faces[i].basis.w = v[i / 2];
		else
			faces[i].basis.w = scalar_product(v[i / 2], -1);
		get_base_3d(&(faces[i].basis.w), &(faces[i].basis.v), \
			&(faces[i].basis.u));
		faces[i].radius = 1;
		faces[i].texture.uv_map.width = faces[i].radius * 2;
		faces[i].texture.uv_map.height = faces[i].texture.uv_map.width;
		faces[i].texture.type[0] = UV_MAP;
		faces[i].texture.type[1] = 0;
		faces[i].texture.uv_map.img_ptr = 0;
	}
}

int			get_skybox(char *line, void **entities)
{
	int			i;
	int			start;
	t_skybox	*skybox;

	if (entities[SKYBOX])
		return (-EMSKD);
	if (!(skybox = malloc(sizeof(t_skybox))))
		return (-EMAF);
	entities[SKYBOX] = skybox;
	if ((start = update_start(line, 2)) == -1)
		return (-SKYBOX);
	get_skybox_faces_basis(skybox->faces);
	i = -1;
	while (++i < 6)
	{
		start = get_texture_map(line, &(skybox->faces[i].texture.uv_map), \
			entities[DISPLAY], start);
		if (start == -1)
			return (-SKYBOX);
		if (i == 5)
			return (check_end_entity_info(line, start, SKYBOX));
		if ((start = update_start(line, start)) == -1)
			return (-SKYBOX);
	}
	return (SKYBOX);
}
