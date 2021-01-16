/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error_message_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:35:01 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/02 11:39:55 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

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
	else if (error_number == CONE)
		ft_putstr_fd("the cone's configuration is not valid", 2);
	else if (error_number == CUBE)
		ft_putstr_fd("the cube's configuration is not valid", 2);
	else if (error_number == PYRAMID)
		ft_putstr_fd("the pyramid's configuration is not valid", 2);
}

static void	scene_parameters_message(int error_number)
{
	if (error_number == RESOLUTION)
		ft_putstr_fd("the resolution's configuration is not valid", 2);
	else if (error_number == AMBIENT)
		ft_putstr_fd("the ambient light's configuration is not valid", 2);
	else if (error_number == CAMERA)
		ft_putstr_fd("the camera's configuration is not valid", 2);
	else if (error_number == LIGHT)
		ft_putstr_fd("the light's configuration is not valid", 2);
}

static void	filters_error_message(int error_number)
{
	if (error_number == SKYBOX)
		ft_putstr_fd("the skybox's configuration is not valid", 2);
	else if (error_number == SEPIA)
		ft_putstr_fd("the sepia's configuration is not valid", 2);
	else if (error_number == ANTI_ALIASING)
		ft_putstr_fd("the anti-aliasing's configuration is not valid", 2);
}

static void	multiple_declaration_error_message(int error_number)
{
	if (error_number == EMRD)
		ft_putstr_fd("multiple resolution declaration", 2);
	if (error_number == EMAD)
		ft_putstr_fd("multiple ambient light declaration", 2);
	else if (error_number == EMSKD)
		ft_putstr_fd("multiple skybox declaration", 2);
	else if (error_number == EMSED)
		ft_putstr_fd("multiple sepia declaration", 2);
	else if (error_number == EMAAD)
		ft_putstr_fd("multiple anti-aliasing declaration", 2);
}

void		display_error_message_utils(int error_number)
{
	if (error_number > 0 && error_number <= LIGHT)
		scene_parameters_message(error_number);
	else if (error_number >= SPHERE && error_number <= PYRAMID)
		shapes_error_message(error_number);
	else if (error_number >= SKYBOX && error_number <= ANTI_ALIASING)
		filters_error_message(error_number);
	else if (error_number >= EMRD && error_number <= EMAAD)
		multiple_declaration_error_message(error_number);
}
