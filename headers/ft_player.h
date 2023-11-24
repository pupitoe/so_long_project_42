/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:25:07 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/24 13:59:14 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLAYER_H
# define FT_PLAYER_H
# include "./ft_pos.h"
# include "ft_map_content.h"
# include "../libft/libft.h"
# include "ft_check_map.h"
# include "./ft_antity.h"
# define KILL_PALYER -1
# define PLAYER_NO_MOVE 0
# define PLAYER_MOVE 1
# define PLAYER_LEFT 3
# define PLAYER_GET_ITEM 2

typedef struct s_player
{
	int	move;
	int	item_count;
	int	item_map;
}				t_player;

int	ft_player_action(char **map, int action);

#endif