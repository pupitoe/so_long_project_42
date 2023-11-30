/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entity.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:27:22 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/30 01:16:34 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENTITY_H
# define FT_ENTITY_H
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

int	ft_entity(char **map);

#endif