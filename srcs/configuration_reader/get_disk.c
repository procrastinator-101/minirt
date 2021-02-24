/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_disk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:08:04 by yarroubi          #+#    #+#             */
/*   Updated: 2021/02/24 16:13:53 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

int	get_disk(char *line, void **entities)
{
	int			start;
	t_disk		*disk;

	if (!(disk = malloc(sizeof(t_disk))))
		return (-EMAF);
	ft_lst_add_head(entities + DISK, disk, DISK);
	disk->texture.uv_map.img_ptr = 0;
	disk->texture.bump_map.img_ptr = 0;
	if ((start = update_start(line, 2)) == -1)
		return (-DISK);
	start = fetch_point_3d(line, &(disk->center), start);
	if ((start = update_start(line, start)) == -1)
		return (-DISK);
	start = fetch_vector_3d(line, &(disk->basis.w), start);
	if ((start = update_start(line, start)) == -1)
		return (-DISK);
	start = get_radius(line, &(disk->radius), start);
	if (start == -1)
		return (-DISK);
	get_base_3d(&(disk->basis.w), &(disk->basis.v), &(disk->basis.u));
	disk->texture.width = disk->radius * 2.0;
	disk->texture.height = disk->texture.width;
	initialise_map_dimension(&(disk->texture));
	return (get_texture(line + start, &(disk->texture), entities[DISPLAY], \
		DISK));
}
