/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:02:13 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/23 13:39:19by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "./headers/ft_check_map.h"
#include "./headers/ft_player.h"
#include "MLX42/include/MLX42/MLX42.h"
#include "./headers/ft_graphique.h"

typedef struct s_mlx_key_param
{
	mlx_t		*mlx;
	char		**map;
	t_graphique *graphique;
	int			player_move;
	int			player_status;
}				t_mlx_key_param;

void	ft_free_param(t_mlx_key_param *param)
{
	if (param->graphique)
		ft_graphique_free(&(param->graphique), param->mlx);
	if (param->map)
		ft_free_tab(param->map);
}

void	ft_get_key_player(t_mlx_key_param *param, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_W)
		param->player_status = ft_player_action(param->map, 'W');
	if (keydata.key == MLX_KEY_A)
		param->player_status = ft_player_action(param->map, 'A');
	if (keydata.key == MLX_KEY_S)
		param->player_status = ft_player_action(param->map, 'S');
	if (keydata.key == MLX_KEY_D)
		param->player_status = ft_player_action(param->map, 'D');

	if (ft_dynamique_change(param->map, param->mlx, param->graphique) == 
		MALLOC_FAIL)
	{
		mlx_close_window(param->mlx);
		ft_error(MALLOC_FAIL);
		return ;
	}
	if (param->player_status == KILL_PALYER)
	{
		mlx_close_window(param->mlx);
		ft_printf("Killed by monster !!!!\n");
	}
	if (param->player_status == PLAYER_LEFT)
	{
		mlx_close_window(param->mlx);
		ft_printf("You win the game GG !\n");
	}
	param->player_move = ft_player_action(param->map, PLAYER_CMD_GET_MOVE);
}

void	mlx_key_bind(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(((t_mlx_key_param *)param)->mlx);
	if (keydata.action == MLX_PRESS && (keydata.key == MLX_KEY_W ||
		keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D  || 
		keydata.key == MLX_KEY_S))
		ft_get_key_player(param, keydata);
	return ;
}

int	ft_set_screen(t_mlx_key_param *param)
{
	if (ft_player_action(param->map, PLAYER_GET_ITEM) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (!(param->graphique = ft_make_graphique_init(param->mlx)))
		return (MALLOC_FAIL);
	if (ft_load_map(param->map, param->mlx, param->graphique) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ft_dynamique_change(param->map, param->mlx, param->graphique) == 
		MALLOC_FAIL)
		return (MALLOC_FAIL);
	return (0);
}

int32_t	main(int argc, char **argv)
{
	t_mlx_key_param	param;
	t_rec		window_size;

	if (argc < 2)
		param.map = ft_check_map("./maps/wad.ber");
	else
		param.map = ft_check_map(argv[1]);
	if (param.map == NULL)
		return (1);
	window_size = ft_get_window(param.map, 32);
	param.mlx = mlx_init(window_size.width, window_size.height, "So_long", 1);
	if (param.mlx == NULL)
		return (ft_free_tab(param.map), 1);
	if (ft_set_screen(&param) == 0)
	{
		mlx_key_hook(param.mlx, &mlx_key_bind, &param);
		mlx_loop(param.mlx);
	}
	else
		ft_error(MALLOC_FAIL);
	ft_free_param(&param);
	mlx_terminate(param.mlx);
	return (0);
}
