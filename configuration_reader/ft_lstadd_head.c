/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:45:33 by yarroubi          #+#    #+#             */
/*   Updated: 2020/02/25 13:47:11 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static void	*choose_type(void *tail, int type)
{
	if (type == CAMERA)
		return (((t_camera *)tail)->next);
	if (type == LIGHT)
		return (((t_light *)tail)->next);
	if (type == SPHERE)
		return (((t_sphere *)tail)->next);
	if (type == PLANE)
		return (((t_plane *)tail)->next);
	if (type == SQUARE)
		return (((t_square *)tail)->next);
	if (type == CYLINDER)
		return (((t_cylinder *)tail)->next);
	if (type == TRIANGLE)
		return (((t_triangle *)tail)->next);
}

void		add_new(void *tail, void *new, int type)
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
			next = choose_type(tail, type);
			if (!next)
				break;
			tail = next;
		}
		add_new(tail, new, type);
	}
}
