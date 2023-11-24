/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:18:28 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/24 13:54:44 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_antity.h"

static int	ft_move_antity(char **map, t_pos start, t_pos end)
{
	if (ft_strchr("C1EM", map[end.y][end.x]))
		return (1);
	if (map[end.y][end.x] == 'P')
		return (-1);
	map[start.y][start.x] = '0';
	map[end.y][end.x] = 'M';
	return (0);
}


static int	ft_antity_random_move(char **map, t_pos antity)
{
	unsigned int	move;
	int				buff;

	move = rand() % 4;
	buff = 0;
	if (move == 0)
		buff = ft_move_antity(map, antity, (t_pos){antity.x, antity.y - 1, 0});
	if (move == 1)
		buff = ft_move_antity(map, antity, (t_pos){antity.x - 1, antity.y, 0});
	if (move == 2)
		buff = ft_move_antity(map, antity, (t_pos){antity.x, antity.y + 1, 0});
	if (move == 3)
		buff = ft_move_antity(map, antity, (t_pos){antity.x + 1, antity.y, 0});
	return (buff);
}

int	ft_antity(char **map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;	
		while (map[y][x])
		{
			if (map[y][x] == 'M')
			{
				if (ft_antity_random_move(map, (t_pos){x, y, 0}) == -1)
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
