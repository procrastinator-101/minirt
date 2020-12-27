/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:51:13 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/27 11:58:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

int	get_sphere(char *line, void **entities)
{
	int			start;
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		return (-SPHERE);
	ft_lst_add_head(entities + SPHERE, sphere, SPHERE);
	sphere->basis.u = get_coord_3d(1, 0, 0);
	sphere->basis.v = get_coord_3d(0, 1, 0);
	sphere->basis.w = get_coord_3d(0, 0, 1);
	start = update_start(line, 2);
	if (start == -1)
		return (-SPHERE);
	start = fetch_point_3d(line, &(sphere->center), start);
	start = update_start(line, start);
	if (start == -1)
		return (-SPHERE);
	start = get_radius(line, &(sphere->radius), start);
	if (start == -1)
		return (-SPHERE);
	sphere->texture.width = sphere->radius * 2.0;
	sphere->texture.height = sphere->texture.width;
	initialise_map_dimension(&(sphere->texture));
	sphere->mode = STATIC_MODE;
	return (get_texture(line + start, &(sphere->texture), entities[DISPLAY], \
		SPHERE));
}
