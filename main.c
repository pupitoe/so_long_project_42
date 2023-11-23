/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:02:13 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/23 12:58:40 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// int main(void)
// {
	
// 	return (1);
// }
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "./headers/ft_check_map.h"
#include "MLX42/include/MLX42/MLX42.h"
#define WIDTH 256
#define HEIGHT 256

// // Exit the program as failure.
// static void ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(exit_failure);
// }

// Print the window width and height.

// void putrec(mlx_t *mlx, t_pos vec_start, t_pos vec_end)
// {
// 	mlx_image_t* img;
// 	int	top;
// 	int	left;

// 	left = vec_start.y;
// 	top = vec_start.x;
// 	img = mlx_new_image(mlx, vec_end.x - vec_start.x, vec_end.y - vec_start.y);
// 	ft_memset(img->pixels, 100, img->width * img->height * sizeof(int32_t));
// 	if (!img || (mlx_image_to_window(mlx, img, left, top) < 0))
// 		ft_error();
// }
void	ft_key_bindig(void *param)
{
	mlx_t *mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	return ;
}

int32_t	main(void)
{
	char **uwuss = ft_check_map("./maps/wad.ber");

	ft_free_tab(uwuss);
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
	// return (EXIT_SUCCESS);
}