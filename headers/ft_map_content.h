/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_content.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:11:12 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/19 15:58:30 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_CONTENT_H
# define FT_MAP_CONTENT_H
# include "../libft/libft.h"
# include "ft_pos.h"

typedef struct s_item_count
{
	size_t	spawn;
	size_t	items;
	size_t	entity;
	size_t	wall;
	size_t	floor;
	size_t	exit;
	size_t	auther;
}				t_item_count;

t_item_count	*ft_make_item_count(void);
void			ft_put_element(t_item_count *lst, int c);
t_pos			ft_get_spawn(char **map);

#endif