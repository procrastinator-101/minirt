/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hconfi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:42:04 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/24 18:45:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"


int main() {

	void **entities = malloc(10 * sizeof(void *));
	for (int i = 0; i < 10; i++)
		entities[i] = 0;
	if (!get_ambient_light("A 0.15478 29,889,11", entities))
		return (0);

	printf("ratio\t= %f|\n", ((t_ambient *)entities[1])->ratio);
	printf("red\t= %d|\n", ((t_ambient *)entities[1])->red);
	printf("green\t= %d|\n", ((t_ambient *)entities[1])->green);
	printf("blue\t= %d|\n", ((t_ambient *)entities[1])->blue);

	return 0;
}
