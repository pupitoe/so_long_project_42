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

static int	ft_cmp_item(t_item_count *items, t_item_count *items_flood)
{
	if (items->exit == 0)
		return (-1);
	if (items->items != items_flood->items)
		return (-1);
	return (0);
}

static void	ft_flood_fill_rec(t_item_count *item, char **map, t_pos vector)
{
	ft_put_element(item, map[vector.y][vector.x]);
	if (ft_strchr("12ME", map[vector.y][vector.x]))
		return ;
	map[vector.y][vector.x] = '2';
	ft_flood_fill_rec(item, map, (t_pos){vector.x + 1, vector.y, 0});
	ft_flood_fill_rec(item, map, (t_pos){vector.x - 1, vector.y, 0});
	ft_flood_fill_rec(item, map, (t_pos){vector.x, vector.y + 1, 0});
	ft_flood_fill_rec(item, map, (t_pos){vector.x, vector.y - 1, 0});
}

int	ft_flood_fill(char **map, t_item_count *items)
{
	t_item_count	*buffer_item;
	char			**buffer_map;
	int				tmp;

	buffer_map = ft_dump_tab(map);
	if (buffer_map == NULL)
		return (MALLOC_FAIL);
	buffer_item = ft_make_item_count();
	if (buffer_item == NULL)
		return (ft_free_tab(buffer_map), MALLOC_FAIL);
	ft_flood_fill_rec(buffer_item, buffer_map, ft_get_spawn(buffer_map));
	tmp = ft_cmp_item(items, buffer_item);
	free(buffer_item);
	ft_free_tab(buffer_map);
	return (tmp);
}
