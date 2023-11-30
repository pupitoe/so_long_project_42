/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:44:02 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/30 01:21:27 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHIC_H
# define FT_GRAPHIC_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "./ft_pos.h"
# include "ft_error.h"
# define IMG_SIZE 32

typedef struct s_graphic
{
	char				*name;
	mlx_texture_t		*texture;
	mlx_image_t			*img;
	struct s_graphic	*next;
}				t_graphic;

typedef struct s_rec
{
	int	width;
	int	height;
}			t_rec;

void		ft_graphic_add_front(t_graphic **first, t_graphic *front);
void		ft_graphic_addback(t_graphic **start, t_graphic *back);
void		ft_graphic_free(t_graphic **start, mlx_t *mlx);
void		ft_graphic_free_one(t_graphic *ptr, mlx_t *mlx);

int			ft_display_texture(mlx_t *mlx, t_pos pos, mlx_image_t *img);
int			ft_push_map(mlx_t *mlx, int c, t_pos pos, t_graphic *textures);
int			ft_load_map(char **map, mlx_t *mlx, t_graphic *textures);
int			ft_dynamique_change(char **map, mlx_t *mlx, t_graphic*graphic);
int			ft_load_dinamique(mlx_t *mlx, t_graphic **ptr);

t_rec		ft_get_window(char **map, int img_size);

t_graphic	*ft_make_graphic_dynamic(mlx_t *mlx);
t_graphic	*ft_make_graphic_init(mlx_t *mlx);
t_graphic	*ft_set_textures(mlx_t *mlx, char *path, char *name);
t_graphic	*ft_graphic_at(t_graphic *begin, int index);
t_graphic	*ft_graphic_new(mlx_image_t *img, mlx_texture_t *texture,
				char *name);
t_graphic	*ft_graphic_last(t_graphic *start);
t_graphic	*ft_set_textures(mlx_t *mlx, char *path, char *name);

#endif