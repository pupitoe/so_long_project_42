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
		return (-1);
	if (ft_flood_fill(map, items) == -1)
		return (free(items), -1);
	free(items);
	//flood fill
	return (0);
}


int ft_check_map(char *path)
{
	t_list  *lst_map;
	char	**map;
	int		ret;

	lst_map = ft_get_map(path);
	ft_print_lst(lst_map);
	if (lst_map == NULL)
		return (-1);
	map = ft_get_tab(lst_map);
	ft_printf("%w", map);
	ret = ft_map_is_good(lst_map, map);
	ft_lstclear(&lst_map, NULL);
	ft_free_tab(map);
	return (ret);
}