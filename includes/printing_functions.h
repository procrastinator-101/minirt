/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_functions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:54:57 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 17:10:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_FUNCTIONS_H
# define PRINTING_FUNCTIONS_H

# include "configuration_reader.h"

void	ft_print_object_position(void *object, int type);

void	print_entity(void **entities, int type);

void	print_rgb(t_rgb rgb);
void	print_pixel(t_pixel pixel);
void	print_smat_3d(t_smat_3d m);
void	print_coord_3d(t_coord_3d point);
void	print_3d_basis(t_3d_basis basis);
void	print_texture(t_texture *texture);

void	print_resolution(t_resolution *resolution);
void	print_ambient_light(t_ambient *ambient);
void	print_camera(t_camera *camera);
void	print_light(t_light *light);
void	print_sphere(t_sphere *sphere);
void	print_plane(t_plane *plane);
void	print_square(t_square *square);
void	print_cylinder(t_cylinder *cylinder);
void	print_triangle(t_triangle *triangle);
void	print_cone(t_cone *tail);
void	print_cube(t_cube *cube);
void	print_pyramid(t_pyramid *pyramid);
void	print_skybox(t_skybox *skybox);
void	print_sepia(t_sepia *sepia);
void	print_anti_aliasing(t_anti_aliasing *anti_aliasing);

#endif
