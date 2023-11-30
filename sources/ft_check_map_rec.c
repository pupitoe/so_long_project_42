/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_rec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:05:12 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/30 00:25:38 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_check_map.h"

int	ft_map_is_valid_rec(int extremity, size_t width, char *line)
{
	int		diff_1;
	size_t	i;

	diff_1 = 0;
	i = 0;
	while (line[i])
	{
		if (line[0] != '1')
			return (-1);
		if (line[i] != '1')
			diff_1 = 1;
		i++;
	}
	if (i < 1 || line[i - 1] != '1' || i != width || (extremity && diff_1))
		return (-1);
	return (0);
}

int	ft_map_is_rec(t_list *map)
{
	size_t	width;
	size_t	height;
	int		buffer;

	width = ft_strlen((char *)(map->content));
	height = 0;
	while (map)
	{
		if (height == 0 || map->next == NULL)
			buffer = ft_map_is_valid_rec(1, width, map->content);
		else
			buffer = ft_map_is_valid_rec(0, width, map->content);
		if (buffer == -1)
			return (-1);
		map = map->next;
		height++;
	}
	if (height < 3 && width < 3)
		return (-1);
	return (0);
}
