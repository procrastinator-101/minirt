/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hconfi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:42:04 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/24 21:43:17 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"


int main() {

	void **entities = malloc(10 * sizeof(void *));
	for (int i = 0; i < 10; i++)
		entities[i] = 0;
	if (!get_ambient_light("A 0.15478 29,89,11", entities))
		return (0);

	printf("ratio\t= %f|\n", ((t_ambient *)entities[1])->ratio);
	printf("red\t= %d|\n", ((t_ambient *)entities[1])->red);
	printf("green\t= %d|\n", ((t_ambient *)entities[1])->green);
	printf("blue\t= %d|\n", ((t_ambient *)entities[1])->blue);


	if (!get_resolution("R 10 120", entities))
		return (0);

	printf("\n\nwidth = %d\n", ((t_resolution *)entities[0])->width);
	printf("height = %d\n", ((t_resolution *)entities[0])->height);

	if (!get_camera("c \t -50.0,-20,-2563.63    \t0,0,1    70", entities))
		return (0);

	printf("\n\nx = %f\n", ((t_camera *)entities[2])->position.x);
	printf("y = %f\n", ((t_camera *)entities[2])->position.y);
	printf("z = %f\n", ((t_camera *)entities[2])->position.z);

	return 0;
}
