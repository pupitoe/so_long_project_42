/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphyque.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:42:52 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/27 21:04:10 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_graphyque.h"

t_graphique	*ft_graphyque_new(mlx_image_t *img, mlx_texture_t *texture,
	char *name)
{
	t_graphique	*el;

	if (!img || !texture || !name)
		return (NULL);
	el = malloc(sizeof(t_graphique));
	if (el == NULL)
		return (NULL);
	el->img = img;
	el->texture = texture;
	el->name = name;
	el->next = NULL;
	return (el);
}

void	ft_graphyque_add_front(t_graphique **first, t_graphique *front)
{
	t_graphique	*buffer;

	if (front == NULL || first == NULL)
		return ;
	if (*first == NULL)
	{
		*first = front;
		return ;
	}
	buffer = *first;
	*first = front;
	front->next = buffer;
	return ;
}

t_graphique	*ft_graphyque_last(t_graphique *start)
{
	if (start == NULL)
		return (NULL);
	if (start->next == NULL)
		return (start);
	return (ft_graphyque_last(start->next));
}

void	ft_graphyque_addback(t_graphique **start, t_graphique *back)
{
	if (start == NULL || back == NULL)
		return ;
	if (*start == NULL)
	{
		ft_graphyque_add_front(start, back);
		return ;
	}
	(ft_graphyque_last(*start))->next = back;
	return ;
}

void ft_graphyque_free_one(t_graphique *ptr, mlx_t *mlx)
{
	mlx_delete_image(mlx, ptr->img);
	mlx_delete_texture(ptr->texture);
	free(ptr->name);
	free(ptr);
	return ;
}

void	ft_graphyque_free(t_graphique **start, mlx_t *mlx)
{
	t_graphique	*buffer;
	t_graphique	*tmp;

	buffer = *start;
	while (buffer)
	{
		tmp = buffer->next;
		ft_graphyque_free_one(buffer, mlx);
		buffer = tmp;
	}
	*start = NULL;
	return ;
}

t_graphique *ft_set_textures(mlx_t *mlx, char *path, char *name)
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
	element = ft_graphyque_new(img, texture, name);
	if (element == NULL)
		return (mlx_delete_image(mlx, img), mlx_delete_texture(texture), NULL);
	return (element);
}


// void ft_test(mlx_t *mlx)
// {
// 	char 		*el;
// 	t_graphique	*ptr;

// 	el = ft_set_textures(mlx, "../D");
// }