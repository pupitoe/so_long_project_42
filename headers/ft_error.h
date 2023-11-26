/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:54:16 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/26 16:50:36 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# include <errno.h>
# include <stdio.h>
# include "../libft/libft.h"
# define MALLOC_FAIL -12


# define ERROR_REC "Error\nYour map is not a rec or is not enclosed by walls\n"
# define ERROR_ITEM "Error\nCount items is not valid. (one : \
E, one : P, one or many : C)\n"
# define ERROR_FLOOD "Error\nThe player d'ont get any items or/and the exit \
is not accecible\n"
# define ERROR_PATH "Your file is not a .ber\n"

void	ft_error(int err);

#endif