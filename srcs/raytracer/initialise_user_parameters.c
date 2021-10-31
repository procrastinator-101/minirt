/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_user_parameters.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:04:56 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/16 17:08:34 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	initialise_user_parameters(void **entities, int argc)
{
	entities[USER_LIGHT] = entities[LIGHT];
	entities[USER_CAMERA] = entities[CAMERA];
	entities[USER_OBJECT] = entities[CAMERA];
	entities[USER_OBJECT_TYPE] = (void *)CAMERA;
	entities[SAVE_IMAGE] = argc == 3 ? (void *)1 : 0;
}
