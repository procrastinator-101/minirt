/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:45:33 by yarroubi          #+#    #+#             */
/*   Updated: 2020/03/05 15:34:08 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static void	add_new(void *tail, void *new, int type)
{
	if (type == CAMERA)
		((t_camera *)tail)->next = new;
	else if (type == LIGHT)
		((t_light *)tail)->next = new;
	else if (type == SPHERE)
		((t_sphere *)tail)->next = new;
	else if (type == PLANE)
		((t_plane *)tail)->next = new;
	else if (type == SQUARE)
		((t_square *)tail)->next = new;
	else if (type == CYLINDER)
		((t_cylinder *)tail)->next = new;
	else if (type == TRIANGLE)
		((t_triangle *)tail)->next = new;
}

static void	update_previous(void *tail, void *previous, int type)
{
	if (type == CAMERA)
		((t_camera *)tail)->previous = previous;
	else if (type == LIGHT)
		((t_light *)tail)->previous = previous;
	else if (type == SPHERE)
		((t_sphere *)tail)->previous = previous;
	else if (type == PLANE)
		((t_plane *)tail)->previous = previous;
	else if (type == SQUARE)
		((t_square *)tail)->previous = previous;
	else if (type == CYLINDER)
		((t_cylinder *)tail)->previous = previous;
	else if (type == TRIANGLE)
		((t_triangle *)tail)->previous = previous;
}

void		ft_lstadd_head(void **lst_tail, void *new, int type)
{
	void	*tail;
	void	*next;

	tail = *lst_tail;
	if (!tail)
		*lst_tail = new;
	else
	{
		while (tail)
		{
			next = choose_entity_type(tail, type);
			if (next == *lst_tail)
				break ;
			tail = next;
		}
		add_new(tail, new, type);
		update_previous(next, tail, type);
	}
	update_previous(*lst_tail, tail, type);
}
