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

int	ft_do_ra(t_stack *ts, int pos)
{
	while (pos > 1)
	{
		ft_print_op(ts, "ra");
		pos--;
	}
	ft_print_op(ts, "pb");
	return (0);
}

int	ft_do_rra(t_stack *ts, int pos)
{
	while (pos <= ts->len)
	{
		ft_print_op(ts, "rra");
		pos++;
	}
	ft_print_op(ts, "pb");
	return (0);
}

int	ft_find_lower(t_stack *ts, int find)
{
	int	count;
	t_stack *stack;

	count = 1;
	stack = ts->astack;
	while (stack)
	{
		if (find == stack->number)
			return (count);
		count++;
		stack = stack->next;
	}
	return (0);
}

int	ft_search_lower(t_stack *ts)
{
	int a;
	int find;
	int pos;
	int len;

	a = 0;
	pos = 0;
	find = 0;
	len = ts->len;
	while (0 < ts->len)
	{
		if (ts->len == 1)
			break ;
		find = ts->sortedstack[a];
		pos = ft_find_lower(ts, find);
//		printf("pos : %d\n", pos);
		if (pos < (ts->len / 2))
			ft_do_ra(ts, pos);
		else
			ft_do_rra(ts, pos);
		ts->len--;
		a++;
	}
	ts->len = len;
	a = 0;
	while (a < ts->len - 1)
	{
		ft_print_op(ts, "pa");
		a++;
	}
	return (0);
}

int ft_start_algo(t_stack *ts)
{
    if (ft_get_sort_stack(ts) == -1)
		return (-1);
	ft_search_lower(ts);
    return (0);
}




/*	ft_print_op("rra");
	ft_print_op("pb");
	ft_print_op("sa");
	ft_print_op("rra");
	ft_print_op("pa"); */