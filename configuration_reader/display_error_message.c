/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error_message.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:22:40 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 16:30:21 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	display_error_message(int error_number)
{
	if (type == RESOLUTION)
		printf("the resolution's configuration is not valid");
	else if (type == AMBIENT)
		printf("the ambient light's configuration is not valid");
	else if (type == CAMERA)
		printf("the camera's configuration is not valid");
	else if (type == LIGHT)
		printf("the light's configuration is not valid");
	else if (type == SPHERE)
		printf("the sphere's configuration is not valid");
	else if (type == PLANE)
		printf("the plane's configuration is not valid");
	else if (type == SQUARE)
		printf("the square's configuration is not valid");
	else if (type == CYLINDER)
		printf("the cylinder's configuration is not valid");
	else if (type == TRIANGLE)
		printf("the triangle's configuration is not valid");
	printf("\nplease restart the program and enter valid configuration data\n");
}
