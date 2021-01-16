/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:48:19 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/16 17:07:23 by yarroubi         ###   ########.fr       */
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
	initialise_filters(entities);
	initialise_display(&display, entities);
	initialise_user_parameters(entities, argc);
	raytracer(entities[CAMERA], entities, entities[DISPLAY]);
	user_interract(entities, &display);
	return (0);
}
