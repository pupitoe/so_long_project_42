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

	if (ft_map_is_rec(lst_map) == -1)
		return (-1);
	items = ft_check_map_items(lst_map);
	if (items == NULL)
		return (-2);
	if (ft_flood_fill(map, items) == -1)
		return (free(items), -3);
	free(items);
	return (0);
}

char	**ft_check_map(char *path)
{
	t_list	*lst_map;
	char	**map;
	int		ret;

	if (ft_check_map_path(path) == -1)
		return (ft_error(-4), NULL);
	lst_map = ft_get_map(path);
	if (lst_map == NULL)
		return (NULL);
	map = ft_get_tab(lst_map);
	ft_printf("%w", map);
	ret = ft_map_is_good(lst_map, map);
	ft_error(ret);
	ft_lstclear(&lst_map, NULL);
	if (ret < 0)
	{
		ft_free_tab(map);
		return (NULL);
	}
	return (map);
}
