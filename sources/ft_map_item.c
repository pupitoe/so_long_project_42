/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:32:59 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/18 17:10:51 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../headers/ft_map_item.h"

t_item_count	*ft_make_item_count(void)
{
	t_item_count	*lst;
	
	lst = malloc(sizeof(t_item_count));
	if (lst == NULL)
		return (NULL);
	lst->spawn = 0;
	lst->items = 0;
	lst->entity = 0;
	lst->wall = 0;
	lst->floor = 0;
	lst->exit = 0;
	lst->auther = 0;
	return (lst);
}

void	ft_put_element(t_item_count *lst, int c)
{
	if (c == '1')
		lst->wall += 1;
	else if (c == '0')
		lst->floor += 1;
	else if (c == 'C')
		lst->items += 1;
	else if (c == 'E')
		lst->exit += 1;
	else if (c == 'P')
		lst->spawn += 1;
	else if (c == 'M')
		lst->entity += 1;
	else
		lst->auther += 1;
}
