/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:52:58 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/19 19:53:32 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_error.h"


void    ft_error(int err)
{
	if (errno == EFAULT)
		perror("Error\n");
	if (err == -1)
		ft_printf(ERROR_REC);
	if (err == -2)
		ft_printf(ERROR_ITEM);
	if (err == -3)
		ft_printf(ERROR_FLOOD);
}
