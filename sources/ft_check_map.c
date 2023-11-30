/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:25:07 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/14 20:58:58 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_check_map.h"

int	ft_map_is_good(t_list *lst_map, char **map)
{
	t_item_count	*items;

	if (ft_map_is_rec(lst_map) < 0)
		return (ERROR_REC);
	items = ft_check_map_items(map);
	if (items == NULL)
		return (ERROR_ITEM);
	if (ft_flood_fill(map, items) < 0)
		return (free(items), ERROR_FLOOD);
	free(items);
	return (0);
}

char	**ft_check_map(char *path)
{
	t_list	*lst_map;
	char	**map;
	int		ret;

	if (ft_check_map_path(path) == -1)
		return (ft_error(ERROR_PATH), NULL);
	lst_map = ft_get_map(path);
	if (lst_map == NULL)
		return (NULL);
	map = ft_get_tab(lst_map);
	if (map == NULL)
		return (ft_lstclear(&lst_map, &free), ft_error(MALLOC_FAIL), NULL);
	ret = ft_map_is_good(lst_map, map);
	ft_error(ret);
	ft_lstclear(&lst_map, NULL);
	if (ret < 0)
		return (ft_free_tab(map), NULL);
	return (map);
}
