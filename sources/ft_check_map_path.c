/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:01:34 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/23 12:21:08 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_check_map.h"

int	ft_check_map_path(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 4)
		return (-1);
	if (ft_strcmp_s2(path + len - 4, ".ber"))
		return (-1);
	return (0);
}
