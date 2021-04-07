/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_what_operation2(t_stack *ts)
{
	if (!ft_strcmp(ts->line, "rr"))
	{
		if (ft_rotate(ts, 1) == -1 || ft_rotate(ts, 2) == -1)
			return (-1);
		return (0);
	}
	if (!ft_strcmp(ts->line, "rra"))
		return (ft_rev_rotate(ts, 1));
	if (!ft_strcmp(ts->line, "rrb"))
		return (ft_rev_rotate(ts, 2));
	if (!ft_strcmp(ts->line, "rrr"))
	{
		if (ft_rev_rotate(ts, 1) == -1 || ft_rev_rotate(ts, 2) == -1)
			return (-1);
		return (0);
	}
	return (-1);
}

int	ft_what_operation(t_stack *ts)
{
	if (!ft_strcmp(ts->line, "sa"))
		return (ft_swap(ts, 1));
	if (!ft_strcmp(ts->line, "sb"))
		return (ft_swap(ts, 2));
	if (!ft_strcmp(ts->line, "ss"))
	{
		if (ft_swap(ts, 1) == -1 || ft_swap(ts, 2) == -1)
			return (-1);
		return (0);
	}
	if (!ft_strcmp(ts->line, "pa"))
		return (ft_push(ts, 1));
	if (!ft_strcmp(ts->line, "pb"))
		return (ft_push(ts, 2));
	if (!ft_strcmp(ts->line, "ra"))
		return (ft_rotate(ts, 1));
	if (!ft_strcmp(ts->line, "rb"))
		return (ft_rotate(ts, 2));
	return (ft_what_operation2(ts));
}

void	ft_print_op2(t_stack *ts, char *str)
{
	if (!ft_strcmp(str, "rb"))
	{
		ft_putendl_fd("rb", 1);
		if (ft_rotate(ts, 2) == -1)
			ft_exit(ts, "Error", 2);
	}
	if (!ft_strcmp(str, "rra"))
	{
		ft_putendl_fd("rra", 1);
		if (ft_rev_rotate(ts, 1) == -1)
			ft_exit(ts, "Error", 2);
	}
	if (!ft_strcmp(str, "rrb"))
	{
		ft_putendl_fd("rrb", 1);
		if (ft_rev_rotate(ts, 2) == -1)
			ft_exit(ts, "Error", 2);
	}
	if (!ft_strcmp(str, "ra"))
	{
		ft_putendl_fd("ra", 1);
		if (ft_rotate(ts, 1) == -1)
			ft_exit(ts, "Error", 2);
	}
}

void	ft_print_op(t_stack *ts, char *str)
{
	if (!ft_strcmp(str, "sa"))
	{
		ft_putendl_fd("sa", 1);
		if (ft_swap(ts, 1) == -1)
			ft_exit(ts, "Error", 2);
	}
	if (!ft_strcmp(str, "pa"))
	{
		ft_putendl_fd("pa", 1);
		if (ft_push(ts, 1) == -1)
			ft_exit(ts, "Error", 2);
	}
	if (!ft_strcmp(str, "pb"))
	{
		ft_putendl_fd("pb", 1);
		if (ft_push(ts, 2) == -1)
			ft_exit(ts, "Error", 2);
	}
	ft_print_op2(ts, str);
}
