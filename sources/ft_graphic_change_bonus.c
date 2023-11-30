/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_change_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:18:49 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/30 15:45:40 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_graphic.h"

int	ft_set_text(t_mlx_key_param *param)
{
	char	*str;

	str = ft_itoa(param->player_move);
	if (str == NULL)
	{
		mlx_close_window(param->mlx);
		return (MALLOC_FAIL);
	}
	if (param->str_move)
		mlx_delete_image(param->mlx, param->str_move);
	param->str_move = mlx_put_string(param->mlx, str, 0, 0);
	free(str);
	if (param->str_move == NULL)
		return (MALLOC_FAIL);
	return (0);
}
