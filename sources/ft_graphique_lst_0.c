/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphique_lst_0.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:16:22 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/30 01:15:09 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_graphique.h"

t_graphique	*ft_graphique_new(mlx_image_t *img, mlx_texture_t *texture,
	char *name)
{
	t_graphique	*el;

	if (!img || !texture || !name)
		return (NULL);
	el = malloc(sizeof(t_graphique));
	if (el == NULL)
		return (NULL);
	el->img = img;
	el->texture = texture;
	el->name = name;
	el->next = NULL;
	return (el);
}

void	ft_graphique_add_front(t_graphique **first, t_graphique *front)
{
	t_graphique	*buffer;

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

t_graphique	*ft_graphique_last(t_graphique *start)
{
	if (start == NULL)
		return (NULL);
	if (start->next == NULL)
		return (start);
	return (ft_graphique_last(start->next));
}

void	ft_graphique_addback(t_graphique **start, t_graphique *back)
{
	if (start == NULL || back == NULL)
		return ;
	if (*start == NULL)
	{
		ft_graphique_add_front(start, back);
		return ;
	}
	(ft_graphique_last(*start))->next = back;
	return ;
}

t_graphique	*ft_graphique_at(t_graphique *begin, int index)
{
	if (begin == NULL || index < 0)
		return (NULL);
	if (!index)
		return (begin);
	if (begin->next == NULL)
		return (begin);
	return (ft_graphique_at(begin->next, index - 1));
}
