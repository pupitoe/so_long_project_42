/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antity.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:27:22 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/25 18:28:28 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ANTITY_H
# define FT_ANTITY_H
# include <math.h>
# include "./ft_pos.h"
# include "../libft/libft.h"
# define ENTITY_KILL -1
# define ENTITY_NO_KILL 0
# define ENTITY_NO_MOVE 1
# define ENTITY_W 0
# define ENTITY_A 1
# define ENTITY_S 2
# define ENTITY_D 3

int	ft_antity(char **map);

#endif