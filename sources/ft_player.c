/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:27:48 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/23 13:50:16 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_player.h"

int	entyty_fdp(void)
{
	return (0);
}

static int	player_change_map(char **map, t_pos player, t_pos dest)
{
	int	buffer;

	buffer = 1;
	if (map[player.y + dest.y][player.x + dest.x] == '1')
		return (0);
	else if (map[player.y + dest.y][player.x + dest.x] == 'M')
		return (-1);
	else if (map[player.y + dest.y][player.x + dest.x] == 'E')
		return (3);
	else
	{
		if (map[player.y + dest.y][player.x + dest.x] == 'C')
			buffer = 2;
		map[player.y][player.x] = '0';
		map[player.y + dest.y][player.x + dest.x] = 'P';
	}
	return (buffer);
}

static int	ft_player_move(char **map, int action)
{
	int	buffer;

	buffer = 0;
	if (action == 'W')
		buffer = player_change_map(map, ft_get_spawn(map), (t_pos){0, -1, 0});
	if (action == 'A')
		buffer = player_change_map(map, ft_get_spawn(map), (t_pos){-1, 0, 0});
	if (action == 'S')
		buffer = player_change_map(map, ft_get_spawn(map), (t_pos){0, 1, 0});
	if (action == 'D')
		buffer = player_change_map(map, ft_get_spawn(map), (t_pos){1, 0, 0});
	if (entyty_fdp())
		return (-1);
	return (buffer);
}

int	ft_player_action(char **map, int action)
{
	static t_player	player = {0, 0, 0};
	int				buffer;

	if (ft_strchr("WASD", action))
	{
		buffer = ft_player_move(map, action);
		player.move += buffer;
		return (buffer);
	}
	if (action == 1)
		return (player.move);
	if (action == 2)
		return (player.item_count);
	return (0);
}
