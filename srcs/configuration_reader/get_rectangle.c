/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rectangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:31:30 by yarroubi          #+#    #+#             */
/*   Updated: 2021/02/24 16:33:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

static int	get_dimension(t_rectangle *rectangle, char *line, int start)
{
}

int	get_rectangle(char *line, void **entities)
{
	int			start;
	t_rectangle	*rectangle;

	if (!(rectangle = malloc(sizeof(t_rectangle))))
		return (-EMAF);
	ft_lst_add_head(entities + rectangle, rectangle, rectangle);
	rectangle->parent = 0;
	rectangle->texture.uv_map.img_ptr = 0;
	rectangle->texture.bump_map.img_ptr = 0;
	if ((start = update_start(line, 2)) == -1)
		return (-rectangle);
	start = fetch_point_3d(line, &(rectangle->position), start);
	if ((start = update_start(line, start)) == -1)
		return (-rectangle);
	start = fetch_vector_3d(line, &(rectangle->basis.w), start);
	if ((start = update_start(line, start)) == -1)
		return (-rectangle);
	if ((start = get_radius(line, &(rectangle->radius), start)) == -1)
		return (-rectangle);
	get_base_3d(&(rectangle->basis.w), &(rectangle->basis.v), &(rectangle->basis.u));
	rectangle->texture.width = rectangle->radius * 2.0;
	rectangle->texture.height = rectangle->texture.width;
	initialise_map_dimension(&(rectangle->texture));
	return (get_texture(line + start, &(rectangle->texture), entities[DISPLAY], \
		rectangle));
}
