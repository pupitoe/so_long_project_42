/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:07:58 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/30 00:35:14 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_check_map.h"

t_list	*ft_put_line(t_list **lst, int fd)
{
	char	*line;
	char	*end_line;
	t_list	*element;

	line = get_next_line(fd);
	if (line == NULL)
		return (*lst);
	end_line = ft_strchr(line, '\n');
	if (end_line)
		(*end_line) = '\0';
	element = ft_lstnew(line);
	if (element == NULL)
		return (free(line), NULL);
	ft_lstadd_back(lst, element);
	return (ft_put_line(lst, fd));
}

char	**ft_get_tab(t_list *lst)
{
	char	**tabs;
	int		lst_size;
	int		i;

	lst_size = ft_lstsize(lst);
	tabs = malloc((lst_size + 1) * sizeof(char **));
	if (tabs == NULL)
		return (NULL);
	tabs[lst_size] = NULL;
	i = 0;
	while (i < lst_size)
	{
		tabs[i] = lst->content;
		lst = lst->next;
		i++;
	}
	return (tabs);
}

t_list	*ft_get_map(char *path)
{
	int		fd;
	t_list	*map;

	fd = open(path, O_RDONLY);
	map = NULL;
	if (fd == -1)
		return (NULL);
	if (!(ft_put_line(&map, fd)))
		ft_lstclear(&map, &free);
	close(fd);
	return (map);
}
