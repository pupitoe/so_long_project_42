/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:25:07 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/19 15:59:53 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLAYER_H
# define FT_PLAYER_H
# include "./ft_pos.h"
# include "../libft/libft.h"

typedef struct s_player
{
	t_pos	pos;
	size_t	hp;
}				t_player;

#endif