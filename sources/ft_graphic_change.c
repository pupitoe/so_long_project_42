/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_change.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:18:49 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/30 15:45:53 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_graphic.h"

int	ft_set_screen(t_mlx_key_param *param)
{
	param->str_move = NULL;
	param->player_move = 0;
	if (ft_player_action(param->map, PLAYER_GET_ITEM) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	param->graphic = ft_make_graphic_init(param->mlx);
	if (param->graphic == NULL)
		return (MALLOC_FAIL);
	if (ft_load_map(param->map, param->mlx, param->graphic) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ft_dynamique_change(param->map, param->mlx, param->graphic)
		== MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ft_set_text(param) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	return (0);
}

void	ft_free_param(t_mlx_key_param *param)
{
	if (param->graphic)
		ft_graphic_free(&(param->graphic), param->mlx);
	if (param->map)
		ft_free_tab(param->map);
	if (param->str_move)
		mlx_delete_image(param->mlx, param->str_move);
}

void	ft_load_dynamique_change(t_mlx_key_param *param)
{
	if (ft_dynamique_change(param->map, param->mlx, param->graphic)
		== MALLOC_FAIL || ft_set_text(param) == MALLOC_FAIL)
	{
		mlx_close_window(param->mlx);
		ft_error(MALLOC_FAIL);
	}
	else if (param->player_status == KILL_PALYER)
	{
		mlx_close_window(param->mlx);
		ft_printf("Killed by monster !!!!\n");
	}
	else if (param->player_status == PLAYER_LEFT)
	{
		mlx_close_window(param->mlx);
		ft_printf("You win the game GG !\n");
	}
}
