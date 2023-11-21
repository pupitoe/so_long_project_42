/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:25:07 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/21 17:55:32 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLAYER_H
# define FT_PLAYER_H
# include "./ft_pos.h"
# include "ft_map_content.h"
# include "../libft/libft.h"

typedef struct s_player
{
	int	move;
	int	item_count;
}				t_player;

#endif