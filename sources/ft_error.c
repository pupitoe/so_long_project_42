/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:52:58 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/30 15:48:54 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_error.h"

void	ft_error(int err)
{
	if (errno == EFAULT)
		perror("Error\n");
	else if (err == MALLOC_FAIL)
		ft_printf("Error\nMalloc fail\n");
	else if (err == ERROR_REC)
		ft_printf("Error\nYour map is not a rec or is not enclosed by walls\n");
	else if (err == ERROR_ITEM)
	{
		ft_printf("Error\nCount items is not valid. (one : E,");
		ft_printf(" one : P, one or many : C)\n");
	}
	else if (err == ERROR_FLOOD)
	{
		ft_printf("Error\nThe player don't get any items or/and the exit");
		ft_printf(" is not accecible\n");
	}
	else if (err == ERROR_PATH)
		ft_printf("Your file is not a .ber\n");
}
