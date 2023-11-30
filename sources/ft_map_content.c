/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:32:59 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/30 00:18:30 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_map_content.h"

t_item_count	*ft_make_item_count(void)
{
	t_item_count	*lst;

	lst = malloc(sizeof(t_item_count));
	if (lst == NULL)
		return (NULL);
	lst->spawn = 0;
	lst->items = 0;
	lst->entity = 0;
	lst->wall = 0;
	lst->floor = 0;
	lst->exit = 0;
	lst->auther = 0;
	return (lst);
}

void	ft_put_element(t_item_count *lst, int c)
{
	if (c == '1')
		lst->wall += 1;
	else if (c == '0')
		lst->floor += 1;
	else if (c == 'C')
		lst->items += 1;
	else if (c == 'E')
		lst->exit += 1;
	else if (c == 'P')
		lst->spawn += 1;
	else if (c == 'M')
		lst->entity += 1;
	else
		lst->auther += 1;
}

t_pos	ft_get_spawn(char **map)
{
	t_pos	spawn;
	char	*car;

	spawn = ft_init_pos();
	spawn.x = -1;
	while (map[spawn.y] && spawn.x == -1)
	{
		car = ft_strchr(map[spawn.y], 'P');
		if (car)
			spawn.x = car - map[spawn.y];
		spawn.y += 1;
	}
	spawn.y -= 1;
	return (spawn);
}
