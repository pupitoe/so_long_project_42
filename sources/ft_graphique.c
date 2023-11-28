/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphique.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:42:52 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/28 01:46:54 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_graphique.h"

t_graphique	*ft_set_textures(mlx_t *mlx, char *path, char *name)
{
	t_graphique		*element;
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	if (name == NULL)
		return (NULL);
	texture = mlx_load_png(path);
	if (texture == NULL)
		return (NULL);
	img = mlx_texture_to_image(mlx, texture);
	if (img == NULL)
		return (mlx_delete_texture(texture), NULL);
	element = ft_graphique_new(img, texture, name);
	if (element == NULL)
		return (mlx_delete_image(mlx, img), mlx_delete_texture(texture), NULL);
	return (element);
}

t_graphique	*ft_test(mlx_t *mlx)
{
	t_graphique	*ptr;
	t_graphique	*tmp;
	int			i;
	char		**files;
	char		*path;

	i = 0;
	files = ft_split("0 1 C", ' ');
	if (files == NULL)
		return (0);
	path = ft_strdup("./r/L.png");
	if (path == NULL)
		return (ft_free_tab(files), NULL);
	ptr = NULL;
	while (files[i])
	{
		path[4] = files[i][0];
		tmp = ft_set_textures(mlx, path, files[i]);
		if (tmp == NULL)
			return (free(path), free(files), ft_graphique_free(&ptr, mlx), NULL);
		ft_graphique_addback(&ptr, tmp);
		i++;
	}	
	return (free(path), free(files), ptr);
}
