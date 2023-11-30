/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_lst_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:17:42 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/28 01:52:33 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_graphic.h"

void	ft_graphic_free_one(t_graphic *ptr, mlx_t *mlx)
{
	mlx_delete_image(mlx, ptr->img);
	mlx_delete_texture(ptr->texture);
	free(ptr->name);
	free(ptr);
	return ;
}

void	ft_graphic_free(t_graphic **start, mlx_t *mlx)
{
	t_graphic	*buffer;
	t_graphic	*tmp;

	if (start == NULL || mlx == NULL)
		return ;
	buffer = *start;
	while (buffer)
	{
		tmp = buffer->next;
		ft_graphic_free_one(buffer, mlx);
		buffer = tmp;
	}
	*start = NULL;
	return ;
}
