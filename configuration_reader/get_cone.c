/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:44:29 by youness           #+#    #+#             */
/*   Updated: 2020/12/29 11:16:38 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static int	get_height_angle(char *line, t_cone *cone, int start)
{
	int	angle;
	int	holder;

	if (!ft_isdigit(line[start]) && line[start] != 43)
		return (-1);
	cone->height = ft_atod_length(line + start, &holder);
	start += holder;
	start = update_start(line, start);
	if (start == -1)
		return (-1);
	if (!ft_isdigit(line[start]) && line[start] != 43)
		return (-1);
	angle = ft_atoi_length(line + start, &holder);
	if (angle > 180)
		return (-1);
	cone->angle = (angle / 2.0) * (M_PI / 180.0);
	return (update_start(line, start + holder));
}

static void	get_texture_dimension(t_cone *cone)
{
	double	tmp;

	tmp = cone->height * cone->height;
	tmp = sqrt(tmp / (cos(cone->angle) * cos(cone->angle)) - tmp);
	cone->texture.width = tmp * 2;
	cone->texture.height = cone->height;
	initialise_map_dimension(&(cone->texture));
}

int			get_cone(char *line, void **entities)
{
	int		start;
	t_cone	*cone;

	if (!(cone = malloc(sizeof(t_cone))))
		return (-EMAF);
	ft_lst_add_head(entities + CONE, cone, CONE);
	start = update_start(line, 2);
	if (start == -1)
		return (-CONE);
	start = fetch_point_3d(line, &(cone->vertex), start);
	start = update_start(line, start);
	if (start == -1)
		return (-CONE);
	start = fetch_vector_3d(line, &(cone->basis.w), start);
	start = update_start(line, start);
	if (start == -1)
		return (-CONE);
	start = get_height_angle(line, cone, start);
	if (start == -1)
		return (-CONE);
	get_texture_dimension(cone);
	get_base_3d(&(cone->basis.w), &(cone->basis.v), &(cone->basis.u));
	return (get_texture(line + start, &(cone->texture), entities[DISPLAY], \
		CONE));
}
