/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:48:19 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/01 19:06:33 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char **argv)
{
	int			i;
	int			error_nb;
	int			file_index;
	void		**entities;
	t_display	display;

	check_prog_arg(argc, argv, &file_index);
	if (!(entities = malloc(sizeof(void *) * ENTITIES_SIZE)))
		return (0);
	i = -1;
	while (++i < ENTITIES_SIZE)
		entities[i] = 0;
	display.mlx_ptr = mlx_init();//handle possible errors 
	if (!display.mlx_ptr)
	{
		display_error_message(EMC);
		exit(EXIT_FAILURE);
	}
	entities[DISPLAY] = &display;
	error_nb = initialise_image_customizers(entities);
	if (error_nb)
		manage_exec_error(entities, error_nb);
	configuration_reader(argv[file_index], entities);
	error_nb = initialise_display(&display, entities);
	if (error_nb)
		manage_exec_error(entities, error_nb);
	entities[USER_LIGHT] = entities[LIGHT];
	entities[USER_CAMERA] = entities[CAMERA];
	entities[USER_OBJECT] = entities[CAMERA];
	entities[USER_OBJECT_TYPE] = (void *)CAMERA;
	entities[SAVE_IMAGE] = argc == 3 ? (void *)1 : 0;
	raytracer(entities[CAMERA], entities, entities[DISPLAY]);
	user_interract(entities, &display);
	return (0);
}
