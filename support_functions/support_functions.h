/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 19:53:35 by yarroubi          #+#    #+#             */
/*   Updated: 2020/09/29 14:49:37 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPPORT_FUNCTIONS_H
# define SUPPORT_FUNCTIONS_H

# include <math.h>

double	ft_min(double a, double b);
double	ft_max(double a, double b);

int		ft_atoi_length(char *str, int *len);
double	ft_atod_length(char *str, int *len);

void	convert_to_lit_end(char *dest, unsigned num, int size);

int		ft_local_endian(void);

#endif
