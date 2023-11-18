/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:34:02 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/18 19:12:25 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POS_H
# define FT_POS_H
# include "../libft/libft.h"
typedef struct	s_pos
{
	int	x;
	int	y;
	int	index;
}				t_pos;

t_pos   *ft_init_pos_ptr(void);
t_pos   ft_init_pos(void);

#endif