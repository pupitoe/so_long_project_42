/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:27:48 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/29 00:56:23 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_player.h"

static int	player_change_map(char **map, t_pos player, t_pos dest)
{
	int	buffer;

	buffer = PLAYER_MOVE;
	if (map[player.y + dest.y][player.x + dest.x] == '1')
		return (PLAYER_NO_MOVE);
	else if (map[player.y + dest.y][player.x + dest.x] == 'M')
		return (KILL_PALYER);
	else if (map[player.y + dest.y][player.x + dest.x] == 'E')
		return (PLAYER_LEFT);
	if (map[player.y + dest.y][player.x + dest.x] == 'C')
		buffer = PLAYER_GET_ITEM;
	map[player.y][player.x] = '0';
	map[player.y + dest.y][player.x + dest.x] = 'P';
	return (buffer);
}

static int	ft_player_move(char **map, int action)
{
	int	buffer;

	buffer = 0;
	if (action == 'W')
		buffer = player_change_map(map, ft_get_spawn(map), (t_pos){0, -1, 0});
	else if (action == 'A')
		buffer = player_change_map(map, ft_get_spawn(map), (t_pos){-1, 0, 0});
	else if (action == 'S')
		buffer = player_change_map(map, ft_get_spawn(map), (t_pos){0, 1, 0});
	else if (action == 'D')
		buffer = player_change_map(map, ft_get_spawn(map), (t_pos){1, 0, 0});
	if (ft_antity(map) == KILL_PALYER)
		return (KILL_PALYER);
	return (buffer);
}

static int	ft_init_player(t_player *player, char **map)
{
	t_item_count	*buffer;

	if (player->item_map)
		return (0);
	buffer = ft_check_map_items(map);
	if (buffer == NULL)
		return (MALLOC_FAIL);
	player->item_map = buffer->items;
	free(buffer);
	return (1);
}

int	ft_player_action(char **map, int action)
{
	static t_player	player = {0, 0, 0};
	int				buffer;

	if (ft_init_player(&player, map) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ft_strchr("WASD", action))
	{
		buffer = ft_player_move(map, action);
		if (buffer == PLAYER_GET_ITEM)
			player.item_count += 1;
		if (buffer == PLAYER_MOVE || buffer == PLAYER_GET_ITEM
			|| (buffer == PLAYER_LEFT && player.item_map == player.item_count))
			player.move += 1;
		if (buffer == PLAYER_LEFT && player.item_map != player.item_count)
			buffer = PLAYER_NO_MOVE;
		return (buffer);
	}
	if (action == PLAYER_CMD_GET_MOVE)
		return (player.move);
	if (action == PLAYER_CMD_GET_ITEM)
		return (player.item_count);
	return (0);
}
