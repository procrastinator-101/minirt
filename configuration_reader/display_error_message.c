/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error_message.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:59:09 by yarroubi          #+#    #+#             */
/*   Updated: 2020/11/01 10:41:29 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration_reader.h"

static void	shapes_error_message(int error_number)
{
	if (error_number == SPHERE)
		ft_putstr_fd("the sphere's configuration is not valid", 2);
	else if (error_number == PLANE)
		ft_putstr_fd("the plane's configuration is not valid", 2);
	else if (error_number == SQUARE)
		ft_putstr_fd("the square's configuration is not valid", 2);
	else if (error_number == CYLINDER)
		ft_putstr_fd("the cylinder's configuration is not valid", 2);
	else if (error_number == TRIANGLE)
		ft_putstr_fd("the triangle's configuration is not valid", 2);
	else if (error_number == RECTANGLE)
		ft_putstr_fd("the rectangle's configuration is not valid", 2);
	else if (error_number == CONE)
		ft_putstr_fd("the cone's configuration is not valid", 2);
	else if (error_number == CUBE)
		ft_putstr_fd("the cube's configuration is not valid", 2);
	else if (error_number == PYRAMID)
		ft_putstr_fd("the pyramid's configuration is not valid", 2);
}

static void	critical_entities_message(int error_number)
{
	if (error_number == RESOLUTION)
		ft_putstr_fd("the resolution's configuration is not valid", 2);
	else if (error_number == AMBIENT)
		ft_putstr_fd("the ambient light's configuration is not valid", 2);
	else if (error_number == CAMERA)
		ft_putstr_fd("the camera's configuration is not valid", 2);
	else if (error_number == LIGHT)
		ft_putstr_fd("the light's configuration is not valid", 2);
	else if (error_number == EMAD)
		ft_putstr_fd("multiple ambient light declaration", 2);
	else if (error_number == EMRD)
		ft_putstr_fd("multiple resolution declaration", 2);
}

static void	execution_error_message(int error_number)
{
	if (error_number == EFR)
		ft_putstr_fd("unsuccesful file reading", 2);
	else if (error_number == EMA)
		ft_putstr_fd("a memory allocation for some block has failed", 2);
	else if (error_number == EMC)
		ft_putstr_fd("the connection with the X server has failed", 2);
	else if (error_number == EWC)
		ft_putstr_fd("the window creation has failed", 2);
	else if (error_number == EIC)
		ft_putstr_fd("the image creation has failed", 2);
}

void		display_error_message(int error_number)
{
	if (error_number > LIGHT && error_number < DISPLAY)
		shapes_error_message(error_number);
	else if (error_number > 0 && error_number < SPHERE)
		critical_entities_message(error_number);
	else if (error_number >= EMRD && error_number <= EECP)
		critical_entities_message(error_number);
	else if (error_number == ANTI_ALIASING)
		ft_putstr_fd("the anti-aliasing configuration is not valid", 2);
	else
		execution_error_message(error_number);
	printf("error number : %d\n", error_number);
	write(2, "\n", 1);
}
