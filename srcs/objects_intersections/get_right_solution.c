/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_right_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:21:56 by youness           #+#    #+#             */
/*   Updated: 2020/04/25 20:25:20 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intersection.h"

double	get_right_solution(double t1, double t2)
{
	if (t1 < t2)
	{
		if (t1 >= 0.0)
			return (t1);
		return (t2 >= 0.0 ? t2 : INFINITY);
	}
	else
	{
		if (t2 >= 0)
			return (t2);
		return (t1 >= 0.0 ? t1 : INFINITY);
	}
}
