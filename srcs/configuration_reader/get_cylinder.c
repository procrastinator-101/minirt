/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:13:53 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/19 12:08:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

static int	get_extra_parameters(char *line, t_cylinder *cylinder, int start)
{
	int	holder;

	start = get_radius(line, &(cylinder->radius), start);
	if (start == -1)
		return (-1);
	if (!ft_isnumber(line + start))
		return (-1);
	cylinder->height = ft_atod_length(line + start, &holder);
	if (cylinder->height < 0.0)
		return (-1);
	if ((start = update_start(line, start + holder)) == -1)
		return (-1);
	if (!ft_isnumber(line + start))
		return (-1);
	cylinder->caps = ft_atoi_length(line + start, &holder);
	if (cylinder->caps > 1 || cylinder->caps < 0)
		return (-1);
	get_base_3d(&(cylinder->basis.w), &(cylinder->basis.v), \
		&(cylinder->basis.u));
	return (start + holder);
}

int			get_cylinder(char *line, void **entities)
{
	int			start;
	t_cylinder	*cylinder;

	if (!(cylinder = malloc(sizeof(t_cylinder))))
		return (-EMAF);
	ft_lst_add_head(entities + CYLINDER, cylinder, CYLINDER);
	cylinder->texture.uv_map.img_ptr = 0;
	cylinder->texture.bump_map.img_ptr = 0;
	if ((start = update_start(line, 2)) == -1)
		return (-CYLINDER);
	start = fetch_point_3d(line, &(cylinder->position), start);
	if ((start = update_start(line, start)) == -1)
		return (-CYLINDER);
	start = fetch_vector_3d(line, &(cylinder->basis.w), start);
	if ((start = update_start(line, start)) == -1)
		return (-CYLINDER);
	start = get_extra_parameters(line, cylinder, start);
	if ((start = update_start(line, start)) == -1)
		return (-CYLINDER);
	cylinder->texture.width = cylinder->radius * 2.0;
	cylinder->texture.height = cylinder->height;
	initialise_map_dimension(&(cylinder->texture));
	return (get_texture(line + start, &(cylinder->texture), entities[DISPLAY], \
		CYLINDER));
}
