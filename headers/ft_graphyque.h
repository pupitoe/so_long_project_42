/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphyque.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:44:02 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/27 21:01:35 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHYQUE_H
# define FT_GRAPHYQUE_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# define IMG_SIZE 32

typedef struct s_graphique
{
	char				*name;
	mlx_texture_t		*texture;
	mlx_image_t			*img;
	struct s_graphique	*next;
}				t_graphique;

void	ft_graphyque_add_front(t_graphique **first, t_graphique *front);
void	ft_graphyque_addback(t_graphique **start, t_graphique *back);
t_graphique	*ft_graphyque_new(mlx_image_t *img, mlx_texture_t *texture,
	char *name);
t_graphique	*ft_graphyque_last(t_graphique *start);
t_graphique *ft_set_textures(mlx_t *mlx, char *path, char *name);
void	ft_graphyque_free(t_graphique **start, mlx_t *mlx);
void ft_graphyque_free_one(t_graphique *ptr, mlx_t *mlx);

#endif