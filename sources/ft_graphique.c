/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphique.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:42:52 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/28 16:07:20 by tlassere         ###   ########.fr       */
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

int			ft_uwuss(mlx_t *mlx, t_graphique **ptr, char *name, char *path)
{
	char		*dump_name;
	t_graphique	*tmp;
	
	dump_name = ft_strdup(name);
	if (dump_name == NULL)
		return (MALLOC_FAIL);
	tmp = ft_set_textures(mlx, path, dump_name);
	if (tmp == NULL)
		return (free(dump_name), MALLOC_FAIL);
	ft_graphique_addback(ptr, tmp);
	return (1);
}

t_graphique	*ft_test(mlx_t *mlx)
{
	t_graphique	*ptr;

	ptr = NULL;
	if (ft_uwuss(mlx, &ptr, "0", "./r/0.png") == MALLOC_FAIL)
		return (ft_graphique_free(&ptr, mlx), NULL);
	if (ft_uwuss(mlx, &ptr, "1", "./r/1.png") == MALLOC_FAIL)
		return (ft_graphique_free(&ptr, mlx), NULL);
	if (ft_uwuss(mlx, &ptr, "C", "./r/C.png") == MALLOC_FAIL)
		return (ft_graphique_free(&ptr, mlx), NULL);
	if (ft_uwuss(mlx, &ptr, "M", "./r/M/M.png") == MALLOC_FAIL)
		return (ft_graphique_free(&ptr, mlx), NULL);
	if (ft_uwuss(mlx, &ptr, "P", "./r/P/P.png") == MALLOC_FAIL)
		return (ft_graphique_free(&ptr, mlx), NULL);
	if (ft_uwuss(mlx, &ptr, "E", "./r/E.png") == MALLOC_FAIL)
		return (ft_graphique_free(&ptr, mlx), NULL);
	return (ptr);
}
