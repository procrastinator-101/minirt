/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error_message.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:22:40 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 16:38:37 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

void	display_error_message(int error_number)
{
	if (error_number == RESOLUTION)
		printf("the resolution's configuration is not valid");
	else if (error_number == AMBIENT)
		printf("the ambient light's configuration is not valid");
	else if (error_number == CAMERA)
		printf("the camera's configuration is not valid");
	else if (error_number == LIGHT)
		printf("the light's configuration is not valid");
	else if (error_number == SPHERE)
		printf("the sphere's configuration is not valid");
	else if (error_number == PLANE)
		printf("the plane's configuration is not valid");
	else if (error_number == SQUARE)
		printf("the square's configuration is not valid");
	else if (error_number == CYLINDER)
		printf("the cylinder's configuration is not valid");
	else if (error_number == TRIANGLE)
		printf("the triangle's configuration is not valid");
	printf("\nplease restart the program and enter valid configuration data\n");
}
