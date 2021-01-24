/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:15:54 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/24 16:46:45 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printing_functions.h"

void	print_rgb(t_rgb rgb)
{
	printf("\nred\t\t= [%f]\n", rgb.red);
	printf("green\t\t= [%f]\n", rgb.green);
	printf("blue\t\t= [%f]\n", rgb.blue);
}
