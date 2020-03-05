/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:46:56 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/05 18:48:39 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

double	dot_product(coord_3d a, coord_3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
