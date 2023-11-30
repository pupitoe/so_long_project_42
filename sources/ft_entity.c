/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:18:28 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/30 00:17:01 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_entity.h"

static int	ft_move_entity(char **map, t_pos start, t_pos end)
{
	if (ft_strchr("C1EM", map[end.y][end.x]))
		return (ENTITY_NO_MOVE);
	if (map[end.y][end.x] == 'P')
		return (ENTITY_KILL);
	map[start.y][start.x] = '0';
	map[end.y][end.x] = 'M';
	return (ENTITY_NO_KILL);
}

static int	ft_entity_random_move(char **map, t_pos entity)
{
	int	move;
	int	buff;

	move = rand() % 4;
	buff = 0;
	if (move == ENTITY_W)
		buff = ft_move_entity(map, entity, (t_pos){entity.x, entity.y - 1, 0});
	if (move == ENTITY_A)
		buff = ft_move_entity(map, entity, (t_pos){entity.x - 1, entity.y, 0});
	if (move == ENTITY_S)
		buff = ft_move_entity(map, entity, (t_pos){entity.x, entity.y + 1, 0});
	if (move == ENTITY_D)
		buff = ft_move_entity(map, entity, (t_pos){entity.x + 1, entity.y, 0});
	return (buff);
}

int	ft_entity_rec(char **map, t_pos cor)
{
	int	bool_entity;
	int	buffer;

	if (map[cor.y] == NULL)
		return (ENTITY_NO_KILL);
	bool_entity = 0;
	if (map[cor.y][cor.x] == 'M')
		bool_entity = 1;
	if (map[cor.y][cor.x])
		buffer = ft_entity_rec(map, (t_pos){cor.x + 1, cor.y, 0});
	else
		buffer = ft_entity_rec(map, (t_pos){0, cor.y + 1, 0});
	if (bool_entity)
	{
		if (ft_entity_random_move(map, (t_pos){cor.x, cor.y, 0}) == ENTITY_KILL)
			return (ENTITY_KILL);
	}
	return (buffer);
}

int	ft_entity(char **map)
{
	return (ft_entity_rec(map, (t_pos){0, 0, 0}));
}
