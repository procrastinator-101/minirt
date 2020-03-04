/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:49:53 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/04 18:23:18 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "../miniRT.h"

typedef struct	s_ray
{
	t_point_3d	origin;
	t_point_3d	direction;
}				t_ray;

typedef struct	s_intersection
{
	double		distance;
	void		*object;
	int			type;
}				t_intersection;


//possible addition of pixels arguments
int				raytracer(t_camera *camera, void **entities);


t_intersection	get_closest_inter(t_ray ray, void **entity_name);

#endif
