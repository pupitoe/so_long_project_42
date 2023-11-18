/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:53:53 by tlassere          #+#    #+#             */
/*   Updated: 2023/11/18 19:16:24 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_pos.h"

t_pos   *ft_init_pos_ptr(void)
{
    t_pos   *vector;

    vector = malloc(sizeof(t_pos));
    if (vector == NULL)
        return (NULL);
    ft_bzero(vector, sizeof(t_pos));
    return (vector);
}

t_pos   ft_init_pos(void)
{
    t_pos   vector;

    vector.index = 0;
    vector.x = 0;
    vector.y = 0;
    return (vector);
}