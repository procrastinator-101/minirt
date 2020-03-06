/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:48:19 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/06 12:03:24 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(int argc, char **argv)
{
	int		i;
	void	**entities;

	if (argc < 2)
		return (0);
	if (!(entities = malloc(sizeof(void *) * ENTITIES_SIZE)))
		return (0);
	i = -1;
	while (++i < ENTITIES_SIZE)
		entities[i] = 0;
	configuration_reader(argv[1], entities);
	create_pixels(entities);
	raytracer(entities[CAMERA], entities);
	return (0);
}
