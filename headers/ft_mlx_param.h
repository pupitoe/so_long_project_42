/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_param.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:39:05 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/30 15:40:45 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_PARAM_H
# define FT_MLX_PARAM_H
# include "./ft_graphic.h"

typedef struct s_mlx_key_param
{
	mlx_t		*mlx;
	char		**map;
	t_graphic	*graphic;
	int			player_move;
	int			player_status;
	mlx_image_t	*str_move;
}				t_mlx_key_param;

#endif