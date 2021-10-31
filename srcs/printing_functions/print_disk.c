/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_disk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:59:57 by yarroubi          #+#    #+#             */
/*   Updated: 2021/02/24 16:17:43 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_disk(t_disk *disk)
{
	while (disk)
	{
		printf("\n\n=======================================");
		printf(" DISK ");
		printf("=======================================\n");
		print_coord_3d(disk->center);
		printf("radius = %f\n", disk->radius);
		print_3d_basis(disk->basis);
		print_texture(&(disk->texture));
		printf("==========================================");
		printf("==========================================\n");
		disk = disk->next;
	}
}
