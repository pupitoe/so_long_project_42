/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:25:10 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/23 12:15:41 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_MAP_H
# define FT_CHECK_MAP_H
# include "../libft/libft.h"
# include <fcntl.h>
# include "ft_map_content.h"
# include "ft_pos.h"
# include "ft_error.h"

void			ft_print_lst(t_list *lst);
char			**ft_get_tab(t_list *lst);

char			**ft_check_map(char *path);
int				ft_map_is_good(t_list *lst_map, char **map);
/**
 * @param extremity Bottum and top of rec
 * @param width Len of rec
 * @param line Current line iterred
*/
int				ft_map_is_valid_rec(int extremity, size_t width, char *line);
int				ft_map_is_rec(t_list *map);
int				ft_map_fill(char *str, int c);
int				ft_check_map_path(char *path);
int				ft_flood_fill(char **map, t_item_count *items);

t_item_count	*ft_check_map_items(char **map);

t_list			*ft_put_line(t_list **lst, int fd);
t_list			*ft_get_map(char *path);

#endif