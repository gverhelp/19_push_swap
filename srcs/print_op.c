/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:29:52 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 14:29:57 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ft_print_op3(char *str)
{
	if (!ft_strcmp(str, "rra"))
	{
		ft_putendl_fd("rra", 1);
		return (0);
	}
	if (!ft_strcmp(str, "rrb"))
	{
		ft_putendl_fd("rrb", 1);
		return (0);
	}
	if (!ft_strcmp(str, "rrr"))
	{
		ft_putendl_fd("rrr", 1);
		return (0);
	}
	return (-1);
}

int		ft_print_op2(char *str)
{
	if (!ft_strcmp(str, "pb"))
	{
		ft_putendl_fd("pb", 1);
		return (0);
	}
	if (!ft_strcmp(str, "ra"))
	{
		ft_putendl_fd("ra", 1);
		return (0);
	}
	if (!ft_strcmp(str, "rb"))
	{
		ft_putendl_fd("rb", 1);
		return (0);
	}
	if (!ft_strcmp(str, "rr"))
	{
		ft_putendl_fd("rr", 1);
		return (0);
	}
	return (ft_print_op3(str));
}

int		ft_print_op(char *str)
{
	if (!ft_strcmp(str, "sa"))
	{
		ft_putendl_fd("sa", 1);
		return (0);
	}
	if (!ft_strcmp(str, "sb"))
	{
		ft_putendl_fd("sb", 1);
		return (0);
	}
	if (!ft_strcmp(str, "ss"))
	{
		ft_putendl_fd("ss", 1);
		return (0);
	}
	if (!ft_strcmp(str, "pa"))
	{
		ft_putendl_fd("pa", 1);
		return (0);
	}
	return (ft_print_op2(str));
}