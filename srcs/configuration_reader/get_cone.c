/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:44:29 by youness           #+#    #+#             */
/*   Updated: 2021/01/18 11:35:53 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

static int	get_height_angle(char *line, t_cone *cone, int start)
{
	int	angle;
	int	holder;

	if (!ft_isdigit(line[start]) && !ft_issign(line[start]))
		return (-1);
	cone->height = ft_atod_length(line + start, &holder);
	if (cone->height < 0.0)
		return (-1);
	start = update_start(line, start + holder);
	if (start == -1)
		return (-1);
	if (!ft_isdigit(line[start]) && !ft_issign(line[start]))
		return (-1);
	angle = ft_atoi_length(line + start, &holder);
	if (angle < 0 || angle > 180)
		return (-1);
	cone->angle = (angle / 2.0) * (M_PI / 180.0);
	return (update_start(line, start + holder));
}

static void	get_texture_dimension(t_cone *cone)
{
	cone->texture.height = cone->height;
	cone->texture.width = 2 * (tan(cone->angle) * cone->height);
	initialise_map_dimension(&(cone->texture));
}

int			get_cone(char *line, void **entities)
{
	int		start;
	t_cone	*cone;

	if (!(cone = malloc(sizeof(t_cone))))
		return (-EMAF);
	ft_lst_add_head(entities + CONE, cone, CONE);
	cone->texture.uv_map.img_ptr = 0;
	cone->texture.bump_map.img_ptr = 0;
	if ((start = update_start(line, 2)) == -1)
		return (-CONE);
	start = fetch_point_3d(line, &(cone->vertex), start);
	if ((start = update_start(line, start)) == -1)
		return (-CONE);
	start = fetch_vector_3d(line, &(cone->basis.w), start);
	if ((start = update_start(line, start)) == -1)
		return (-CONE);
	start = get_height_angle(line, cone, start);
	if (start == -1)
		return (-CONE);
	get_texture_dimension(cone);
	get_base_3d(&(cone->basis.w), &(cone->basis.v), &(cone->basis.u));
	return (get_texture(line + start, &(cone->texture), entities[DISPLAY], \
		CONE));
}
