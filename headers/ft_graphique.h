/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphyque.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:44:02 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/28 01:46:54 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_graphique_H
# define FT_graphique_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "./ft_pos.h"
# define IMG_SIZE 32

typedef struct s_graphique
{
	char				*name;
	mlx_texture_t		*texture;
	mlx_image_t			*img;
	struct s_graphique	*next;
}				t_graphique;

typedef struct s_rec
{
	int	width;
	int	height;
}			t_rec;

void		ft_graphique_add_front(t_graphique **first, t_graphique *front);
void		ft_graphique_addback(t_graphique **start, t_graphique *back);
t_graphique	*ft_graphique_new(mlx_image_t *img, mlx_texture_t *texture,
				char *name);
t_graphique	*ft_graphique_last(t_graphique *start);
t_graphique	*ft_set_textures(mlx_t *mlx, char *path, char *name);
void		ft_graphique_free(t_graphique **start, mlx_t *mlx);
void		ft_graphique_free_one(t_graphique *ptr, mlx_t *mlx);
t_graphique	*ft_set_textures(mlx_t *mlx, char *path, char *name);
t_graphique	*ft_test(mlx_t *mlx);
t_rec		ft_get_window(char **map, int img_size);
int			ft_display_texture(mlx_t *mlx, t_pos pos, mlx_image_t *img);
int			ft_push_map(mlx_t *mlx, int c, t_pos pos, t_graphique *textures);
int			ft_load_map(char **map, mlx_t *mlx, t_graphique *textures);

#endif