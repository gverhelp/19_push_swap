/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:29:52 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 14:29:57 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_len_is_5(t_stack *ts)
{
	int		pos;
	t_stack *astack;
	t_stack *bstack;

	astack = ts->astack;
	bstack = ts->bstack;
	pos = ft_get_lower_number(ts, ts->astack);
	ft_ra_or_rra(ts, pos, 1);
	return (0);
}

int	ft_len_is_3(t_stack *ts)
{
	t_stack *stack;

	stack = ts->astack;
	if (stack->number > stack->next->number &&
		stack->next->number > stack->next->next->number &&
		stack->number > stack->next->next->number)
	{
		ft_print_op(ts, "sa");
		ft_print_op(ts, "rra");
	}
	else if (stack->number > stack->next->number &&
		stack->next->number < stack->next->next->number &&
		stack->number < stack->next->next->number)
		ft_print_op(ts, "sa");
	else if (stack->number > stack->next->number &&
		stack->next->number < stack->next->next->number &&
		stack->number > stack->next->next->number)
		ft_print_op(ts, "ra");
	else if (stack->number < stack->next->number &&
		stack->next->number > stack->next->next->number &&
		stack->number < stack->next->next->number)
	{
		ft_print_op(ts, "sa");
		ft_print_op(ts, "ra");
	}
	else if (stack->number < stack->next->number &&
		stack->next->number > stack->next->next->number &&
		stack->number > stack->next->next->number)
		ft_print_op(ts, "rra");
	return (0);
}

int	ft_len_is_2(t_stack *ts)
{
	t_stack *stack;

	stack = ts->astack;
	if (stack->number > stack->next->number)
		ft_print_op(ts, "ra");
	return (0);
}

int	ft_wich_algo(t_stack *ts)
{
	if (!ft_check_order(ts))
		return (0);
	if (ts->len == 2)
		ft_len_is_2(ts);
	if (ts->len == 3)
		ft_len_is_3(ts);
	if (ts->len == 5)
		ft_len_is_5(ts);
	return (0);
}

int ft_start_algo(t_stack *ts)
{
    if (ft_get_sort_stack(ts) == -1)
		return (-1);
	ft_wich_algo(ts);
    return (0);
}




/*	ft_print_op("rra");
	ft_print_op("pb");
	ft_print_op("sa");
	ft_print_op("rra");
	ft_print_op("pa"); */


/* 
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

int	ft_ra_or_rra(t_stack *ts)
{
	int a;
	int find;
	int pos;
	int len;

	a = 0;
	pos = 0;
	find = 0;
	len = ts->len;
	while (1 < ts->len)
	{
		find = ts->sortedstack[a];
		pos = ft_find_lower(ts, find);
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
*/