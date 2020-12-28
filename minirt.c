/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:48:19 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/28 18:46:06 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	int			i;
	int			error_nb;
	void		**entities;
	t_display	display;

	check_prog_arg(argc, argv);
	if (!(entities = malloc(sizeof(void *) * ENTITIES_SIZE)))
		return (0);
	i = -1;
	while (++i < ENTITIES_SIZE)
		entities[i] = 0;
	display.mlx_ptr = mlx_init();
	if (!display.mlx_ptr)
	{
		display_error_message(EMC);
		exit(EXIT_FAILURE);
	}
	entities[DISPLAY] = &display;
	error_nb = initialise_filters(entities);
	if (error_nb)
		manage_exec_error(entities, error_nb);
	configuration_reader(argv[1], entities);
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
