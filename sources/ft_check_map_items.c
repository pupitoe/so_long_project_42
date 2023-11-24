/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_items.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:32:59 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/24 19:53:50 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_check_map.h"

void	ft_put_content_lines(char **map, t_item_count *lst)
{
	size_t	i;

	while (*map)
	{
		i = 0;
		while ((*map)[i])
		{
			ft_put_element(lst, (*map)[i]);
			i++;
		}
		map++;
	}
}

static int	ft_check_content(t_item_count *lst)
{
	if (lst->auther > 0)
		return (-1);
	if (lst->exit != 1 || lst->spawn != 1)
		return (-1);
	if (lst->items < 1)
		return (-1);
	return (0);
}

t_item_count	*ft_check_map_items(char  **map)
{
	t_item_count	*lst;

	lst = ft_make_item_count();
	if (lst == NULL)
		return (NULL);
	ft_put_content_lines(map, lst);
	if (ft_check_content(lst) == -1)
		return (free(lst), NULL);
	return (lst);
}
