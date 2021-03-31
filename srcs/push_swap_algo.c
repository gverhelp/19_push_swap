/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:29:52 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 14:29:57 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    ft_print_op(char *str)
{
	if (!ft_strcmp(str, "sa"))
		ft_putendl_fd("sa", 1);
	if (!ft_strcmp(str, "sb"))
		ft_putendl_fd("sb", 1);
	if (!ft_strcmp(str, "ss"))
		ft_putendl_fd("ss", 1);
	if (!ft_strcmp(str, "pa"))
		ft_putendl_fd("pa", 1);
	if (!ft_strcmp(str, "pb"))
		ft_putendl_fd("pb", 1);
	if (!ft_strcmp(str, "ra"))
		ft_putendl_fd("ra", 1);
	if (!ft_strcmp(str, "rb"))
		ft_putendl_fd("rb", 1);
	if (!ft_strcmp(str, "rr"))
		ft_putendl_fd("rr", 1);
	if (!ft_strcmp(str, "rra"))
		ft_putendl_fd("rra", 1);
	if (!ft_strcmp(str, "rrb"))
		ft_putendl_fd("rrb", 1);
	if (!ft_strcmp(str, "rrr"))
		ft_putendl_fd("rrr", 1);
}

int ft_start_algo(t_stack *ts)
{
    if (ft_sort_stack(ts) == -1)
		return (-1);
    return (0);
}




/*	ft_print_op("rra");
	ft_print_op("pb");
	ft_print_op("sa");
	ft_print_op("rra");
	ft_print_op("pa"); */