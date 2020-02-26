/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:13:26 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/26 15:13:12 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	fill_height(char *line, t_square *square, int start)
{
	int holder;

	if (!ft_isdigit(line[start]) && line[start] != '+')
		return (-1);
	square->height = ft_atoi_length(line + start, &holder);
	return (start + holder);
}

int			get_square(char *line, void **entities)
{
	int			start;
	t_square	*square;

	if (!(square = malloc(sizeof(t_square))))
		return (-SQUARE);
	ft_lstadd_head(&(entities[SQUARE]), square, SQUARE);
	square->next = 0;
	start = update_start(line, 2);
	if (start == -1)
		return (-SQUARE);
	start = fetch_point_3d(line, &(square->square_point), start);
	start = update_start(line, start);
	if (start == -1)
		return (-SQUARE);
	start = fetch_vector_3d(line, &(square->orientation_vec), start);
	start = update_start(line, start);
	if (start == -1)
		return (-SQUARE);
	start = fill_height(line, square, start);
	start = update_start(line, start);
	if (start == -1)
		return (-SQUARE);
	if (fetch_rgb(line, &(square->rgb), start) == -1)
		return (-SQUARE);
	return (SQUARE);
}
