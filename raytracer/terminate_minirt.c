/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_minirt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:15:56 by youness           #+#    #+#             */
/*   Updated: 2020/06/26 21:22:54 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	terminate_minirt(void *param)
{
	destroy_entities(param);
	printf("minirt has been successfully terminated\n");
	exit(EXIT_SUCCESS);
	return (0);
}
