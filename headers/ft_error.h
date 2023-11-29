/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:54:16 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/29 01:10:53 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# include <errno.h>
# include <stdio.h>
# include "../libft/libft.h"
# define MALLOC_FAIL -12
# define ERROR_REC -1
# define ERROR_ITEM -2
# define ERROR_FLOOD -3
# define ERROR_PATH -4

void	ft_error(int err);

#endif