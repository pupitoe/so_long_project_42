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


typedef struct hukk
{
	mlx_t	*mlx;
	
} t_hukk;


typedef struct s_rec
{
	int	width;
	int height;
} t_rec;


t_rec	ft_get_window(char **map, int img_size)
{
	t_rec window_size;

	window_size.width = img_size * ft_strlen(map[0]);
	window_size.height = 0;
	while (*map)
	{
		window_size.height += 1;
		map++;
	}
	window_size.height *= img_size;
	return (window_size);
}

typedef	struct s_textures
{
	mlx_texture_t	*wall_t;
	mlx_image_t		*wall_i;
	mlx_texture_t	*floor_t;
	mlx_image_t		*floor_i;
	mlx_texture_t	*entity_t;
	mlx_image_t		*entity_i;
	mlx_texture_t	*player_t;
	mlx_image_t		*player_i;
	mlx_texture_t	*item_t;
	mlx_image_t		*item_i;
	mlx_texture_t	*exit_t;
	mlx_image_t		*exit_i;
}				t_textures;


// check if fail load images/textures
// t_textures	ft_set_textures(mlx_t *mlx)
// {
// 	t_textures	textures;

// 	textures.wall_t = mlx_load_png("./resource_pack/1.png");
// 	textures.wall_i = mlx_texture_to_image(mlx, textures.wall_t);
// 	textures.floor_t = mlx_load_png("./resource_pack/0.png");
// 	textures.floor_i = mlx_texture_to_image(mlx, textures.floor_t);
// 	textures.entity_t = mlx_load_png("./resource_pack/M/M.png");
// 	textures.entity_i = mlx_texture_to_image(mlx, textures.entity_t);
// 	textures.player_t = mlx_load_png("./resource_pack/P/P_0.png");
// 	textures.player_i = mlx_texture_to_image(mlx, textures.player_t);
// 	textures.item_t = mlx_load_png("./resource_pack/C.png");
// 	textures.item_i = mlx_texture_to_image(mlx, textures.item_t);
// 	textures.item_t = mlx_load_png("./resource_pack/C.png");
// 	textures.item_i = mlx_texture_to_image(mlx, textures.item_t);
// 	return (textures);
// }

int	ft_display_texture(mlx_t *mlx, t_pos pos, mlx_image_t *img)
{
	if (mlx_image_to_window(mlx, img, pos.x * 32, pos.y * 32) < 0)
		return (-1);
	return (0);
}

int	ft_push_map(mlx_t *mlx, int c, t_pos pos, t_textures textures)
{
	if (c == 'P')
		return (ft_display_texture(mlx, pos, textures.player_i));
	if (c == '1')
		return (ft_display_texture(mlx, pos, textures.wall_i));
	if (c == '0')
		return (ft_display_texture(mlx, pos, textures.floor_i));
	if (c == 'C')
		return (ft_display_texture(mlx, pos, textures.item_i));
	if (c == 'M')
		return (ft_display_texture(mlx, pos, textures.entity_i));
	return (0);
}

int	ft_load_map(char **map, mlx_t *mlx, t_textures textures)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_push_map(mlx, map[y][x], (t_pos){x, y, 0}, textures) == -1)
				return (-1);
			x++;
		}
		y++;
	}	
	return (0);
}



int32_t	main(void)
{
	// char **map = ft_check_map("./maps/wad.ber");

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
	
	// t_rec		window_size;
	// t_textures 	textures;
	// mlx_t	*mlx;
	// window_size = ft_get_window(map, 32);	

	// if (!(mlx = mlx_init(window_size.width, window_size.height, "So_long", 1)))
	// 	return (EXIT_FAILURE);
	// textures = ft_set_textures(mlx);
	// ft_load_map(map, mlx, textures);
	// mlx_key_hook(mlx, &mlx_key_bind, mlx);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	// free(map);
	// return (EXIT_SUCCESS);
}