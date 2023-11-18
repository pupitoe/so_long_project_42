/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_flood_fill.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:05:13 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/18 17:05:13 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_check_map.h"

int	ft_cmp_item(t_item_count *items, t_item_count *items_flood)
{
	if (items->exit != items_flood->exit)
		return (-1);
	if (items->items != items_flood->items)
		return (-1);
	return (0);
}

int	ft_flood_fill(char **map, t_item_count *items)
{
	t_item_count	*buffer;
	int				tmp;

	buffer = ft_make_item_count();
	if (buffer == NULL)
		return (-1);
	tmp = ft_cmp_item(items, buffer);
	free(buffer);
	return (tmp);
	ft_flood_fill(map, items);
}