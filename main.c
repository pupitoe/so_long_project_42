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
#include <stdio.h>
#include "./headers/ft_check_map.h"
#include "./headers/ft_player.h"
#include "MLX42/include/MLX42/MLX42.h"
#include "./headers/ft_graphique.h"
#define WIDTH 256
#define HEIGHT 256

typedef struct s_mlx_key_param
{
	mlx_t		*mlx;
	char		**map;
	t_graphique *graphique;
}				t_mlx_key_param;

void	ft_free_param(t_mlx_key_param *param)
{
	if (param->graphique)
		ft_graphique_free(&(param->graphique), param->mlx);
	if (param->map)
		ft_free_tab(param->map);
}

void	ft_close_window(t_mlx_key_param *param)
{
	ft_free_param(param);
	mlx_close_window(param->mlx);
}

void	mlx_key_bind(mlx_key_data_t keydata, void *param)
{
	mlx_t *mlx;

	mlx = param;
	(void)mlx;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		ft_close_window(param);
	return ;
}

int32_t	main(void)
{
	t_mlx_key_param	param;
	t_rec		window_size;

	param.map = ft_check_map("./maps/wad.ber");
	if (param.map == NULL)
		return (EXIT_FAILURE);
	window_size = ft_get_window(param.map, 32);
	param.mlx = mlx_init(window_size.width, window_size.height, "So_long", 1);
	if (param.mlx == NULL)
		return (EXIT_FAILURE);
	if (!(param.graphique = ft_test(param.mlx)))
		return (ft_close_window(&param), EXIT_FAILURE);
	ft_load_map(param.map, param.mlx, param.graphique);
	// ft_printf("uwu %s\n", graphique->name);
	mlx_key_hook(param.mlx, &mlx_key_bind, &param);
	mlx_loop(param.mlx);
	mlx_terminate(param.mlx);
	// ft_free_tab(param.map);
	// ft_graphique_free(&(param.graphique), param.mlx);
	printf("uww\n");
	return (EXIT_SUCCESS);
}
