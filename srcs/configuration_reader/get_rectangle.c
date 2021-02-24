/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rectangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:31:30 by yarroubi          #+#    #+#             */
/*   Updated: 2021/02/24 16:59:06 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

static int	get_dimensions(t_rectangle *rectangle, char *line, int start)
{
	int		holder;

	if (!ft_isnumber(line + start))
		return (-1);
	rectangle->width = ft_atod_length(line + start, &holder);
	if (rectangle->width < 0.0)
		return (-1);
	start = update_start(line, start + holder);
	if (start == -1)
		return (-1);
	if (!ft_isnumber(line + start))
		return (-1);
	rectangle->height = ft_atod_length(line + start, &holder);
	if (rectangle->width < 0.0)
		return (-1);
	return (update_start(line, start + holder));
}

int			get_rectangle(char *line, void **entities)
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
		return (-RECTANGLE);
	start = fetch_point_3d(line, &(rectangle->position), start);
	if ((start = update_start(line, start)) == -1)
		return (-RECTANGLE);
	start = fetch_vector_3d(line, &(rectangle->basis.w), start);
	if ((start = update_start(line, start)) == -1)
		return (-RECTANGLE);
	if ((start == get_dimensions(rectangle, line, start)) == -1)
		return (-RECTANGLE);
	get_base_3d(&(rectangle->basis.w), &(rectangle->basis.v), \
		&(rectangle->basis.u));
	rectangle->texture.width = rectangle->radius * 2.0;
	rectangle->texture.height = rectangle->texture.width;
	initialise_map_dimension(&(rectangle->texture));
	return (get_texture(line + start, &(rectangle->texture), \
		entities[DISPLAY], RECTANGLE));
}
