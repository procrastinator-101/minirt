/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:48:19 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/02 12:46:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	int			i;
	void		**entities;
	t_display	display;

	check_prog_arg(argc, argv);
	if (!(entities = malloc(sizeof(void *) * ENTITIES_SIZE)))
		return (0);
	i = -1;
	while (++i < ENTITIES_SIZE)
		entities[i] = 0;
	display.win_ptr = 0;
	display.img_ptr = 0;
	display.mlx_ptr = mlx_init();
	if (!display.mlx_ptr)
		manage_exec_error(entities, EMCF);
	entities[DISPLAY] = &display;
	configuration_reader(argv[1], entities);
	printf("\npre\n");
	initialise_filters(entities);
	printf("\npost\n");
	initialise_display(&display, entities);
	printf("\npost2\n");
	printf("anti-aliasing = %d\n", ((t_anti_aliasing *)entities[ANTI_ALIASING])->factor);
	entities[USER_LIGHT] = entities[LIGHT];
	entities[USER_CAMERA] = entities[CAMERA];
	entities[USER_OBJECT] = entities[CAMERA];
	entities[USER_OBJECT_TYPE] = (void *)CAMERA;
	entities[SAVE_IMAGE] = argc == 3 ? (void *)1 : 0;
	raytracer(entities[CAMERA], entities, entities[DISPLAY]);
	user_interract(entities, &display);
	return (0);
}
