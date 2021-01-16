/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_smat_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:17:38 by youness           #+#    #+#             */
/*   Updated: 2020/06/24 13:48:29 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/configuration_reader.h"

void	print_smat_3d(t_smat_3d m)
{
	printf("\n%f	%f	%f\n", m.v1.x, m.v2.x, m.v3.x);
	printf("%f	%f	%f\n", m.v1.y, m.v2.y, m.v3.y);
	printf("%f	%f	%f\n\n", m.v1.z, m.v2.z, m.v3.z);
}
