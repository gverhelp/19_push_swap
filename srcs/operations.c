/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/04/07 17:24:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_swap(t_stack *ts, int a)
{
	t_stack	*stack;
	int		tmp;

	tmp = 0;
	if (a == 1)
		stack = ts->astack;
	if (a == 2)
		stack = ts->bstack;
	if (!stack || !(stack->next))
		return (-1);
	tmp = stack->number;
	stack->number = stack->next->number;
	stack->next->number = tmp;
	return (0);
}

int	ft_push(t_stack *ts, int a)
{
	if (a == 1)
	{
		if (!ts->bstack)
			return (-1);
		ft_push_stack(&ts->astack, ts->bstack->number);
		ft_pop_stack(&ts->bstack);
		ts->lena++;
		ts->lenb--;
	}
	if (a == 2)
	{
		if (!ts->astack)
			return (-1);
		ft_push_stack(&ts->bstack, ts->astack->number);
		ft_pop_stack(&ts->astack);
		ts->lena--;
		ts->lenb++;
	}
	return (0);
}

int	ft_rotate(t_stack *ts, int a)
{
	t_stack	*top;
	t_stack	*bot;

	if (a == 1)
	{
		if (!ts->astack)
			return (-1);
		if (!ts->astack->next)
			return (0);
		top = ts->astack;
		bot = ft_get_last_elem(ts->astack);
		ts->astack = top->next;
		top->next = NULL;
		bot->next = top;
	}
	if (a == 2)
		return (ft_rotate2(ts));
	return (0);
}

int	ft_rev_rotate(t_stack *ts, int a)
{
	t_stack	*bot;
	t_stack	*before_bot;

	if (a == 1)
	{
		if (!ts->astack)
			return (-1);
		if (!ts->astack->next)
			return (0);
		bot = ft_get_last_elem(ts->astack);
		before_bot = ft_get_before_last_elem(ts->astack);
		before_bot->next = NULL;
		bot->next = ts->astack;
		ts->astack = bot;
	}
	if (a == 2)
		return (ft_rev_rotate2(ts));
	return (0);
}
