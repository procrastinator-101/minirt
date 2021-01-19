/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 19:53:35 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/19 12:02:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPPORT_FUNCTIONS_H
# define SUPPORT_FUNCTIONS_H

# include <math.h>
# include "libft.h"

double	ft_min(double a, double b);
double	ft_max(double a, double b);

int		ft_issign(char c);
int		ft_isnumber(char *num);

int		ft_atoi_length(char *str, int *len);
double	ft_atod_length(char *str, int *len);

char	*ft_strrstr(const char *haystack, const char *needle);

void	convert_to_lit_end(char *dest, unsigned num, int size);

int		ft_local_endian(void);

#endif
