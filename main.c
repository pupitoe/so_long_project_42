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
#define WIDTH 256
#define HEIGHT 256

void	mlx_key_bind(mlx_key_data_t keydata, void *param)
{
	mlx_t *mlx;

	mlx = param;
	(void)mlx;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(mlx);
	return ;
}


int32_t	main(void)
{
	// char **uwuss = ft_check_map("./maps/wad.ber");

	// if (uwuss == NULL)
	// 	return (0);
	// char buffer[1];
	// while (scanf("%c", buffer))
	// {
	// 	if (*buffer == 'p')
	// 		break ;
	// 	ft_printf("nb move %d\n", ft_player_action(uwuss, 1));
	// 	if (ft_player_action(uwuss, ft_toupper(*buffer)) == -1)
	// 		break;
	// 	ft_printf("%w\n", uwuss);
	// }
	// ft_printf("%w\n", uwuss);
	// ft_printf("nb move %d\n", ft_player_action(uwuss, 1));
	// ft_free_tab(uwuss);
	
	mlx_t	*mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "so_long", 1)))
		return (EXIT_FAILURE);

	mlx_key_hook(mlx, &mlx_key_bind, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
	// MLX allows you to define its core behaviour before startup.
	// mlx_set_setting(MLX_MAXIMIZED, true);
	// mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "So_long", true);
	// if (!mlx)
	// 	ft_error();

	// /* Do stuff */

	// // Create and display the image.
	// mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	// if (!img || (mlx_image_to_window(mlx, img, 12, 12) < 0))
	// 	ft_error();

	// // Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(img, 42, 0, 0xFF00FFFF);
	// mlx_put_pixel(img, 80, 0, 0xFF00FFFF);
	// mlx_delete_image(mlx, img);
	// // ft_key_bindig(mlx);
	// // Register a hook and pass mlx as an optional param.
	// // NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_key_bindig, mlx);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
}