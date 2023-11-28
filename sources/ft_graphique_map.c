/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphique_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:00:39 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/28 19:19:39 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_graphique.h"

t_rec	ft_get_window(char **map, int img_size)
{
	t_rec	window_size;

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

int	ft_display_texture(mlx_t *mlx, t_pos pos, mlx_image_t *img)
{
	if (mlx_image_to_window(mlx, img, pos.x * 32, pos.y * 32) < 0)
		return (-1);
	return (0);
}

int	ft_push_map(mlx_t *mlx, int c, t_pos pos, t_graphique *textures)
{
	while (textures)
	{
		if (c == *(textures->name))
			return (ft_display_texture(mlx, pos, textures->img));
		textures = textures->next;
	}
	return (0);
}

int	ft_load_map(char **map, mlx_t *mlx, t_graphique *textures)
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
			if (ft_push_map(mlx, (map[y][x] == '1') + '0',
				(t_pos){x, y, 0}, textures) == -1)
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_dynamique_change(char **map, mlx_t *mlx, t_graphique* graphique)
{
	t_pos	pos;

	pos = (t_pos){0, 0, 0};
	if (ft_load_dinamique(mlx, &graphique) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	graphique = ft_graphique_at(graphique, 2);
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (ft_push_map(mlx, map[pos.y][pos.x], pos, graphique) == -1)
				return (-1);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}