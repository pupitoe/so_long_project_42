/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_lst_0.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:16:22 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/30 01:15:09 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_graphic.h"

t_graphic	*ft_graphic_new(mlx_image_t *img, mlx_texture_t *texture,
	char *name)
{
	t_graphic	*el;

	if (!img || !texture || !name)
		return (NULL);
	el = malloc(sizeof(t_graphic));
	if (el == NULL)
		return (NULL);
	el->img = img;
	el->texture = texture;
	el->name = name;
	el->next = NULL;
	return (el);
}

void	ft_graphic_add_front(t_graphic **first, t_graphic *front)
{
	t_graphic	*buffer;

	if (front == NULL || first == NULL)
		return ;
	if (*first == NULL)
	{
		*first = front;
		return ;
	}
	buffer = *first;
	*first = front;
	front->next = buffer;
	return ;
}

t_graphic	*ft_graphic_last(t_graphic *start)
{
	if (start == NULL)
		return (NULL);
	if (start->next == NULL)
		return (start);
	return (ft_graphic_last(start->next));
}

void	ft_graphic_addback(t_graphic **start, t_graphic *back)
{
	if (start == NULL || back == NULL)
		return ;
	if (*start == NULL)
	{
		ft_graphic_add_front(start, back);
		return ;
	}
	(ft_graphic_last(*start))->next = back;
	return ;
}

t_graphic	*ft_graphic_at(t_graphic *begin, int index)
{
	if (begin == NULL || index < 0)
		return (NULL);
	if (!index)
		return (begin);
	if (begin->next == NULL)
		return (begin);
	return (ft_graphic_at(begin->next, index - 1));
}
