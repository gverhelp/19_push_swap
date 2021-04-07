/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:29:52 by gverhelp          #+#    #+#             */
/*   Updated: 2021/04/07 01:04:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_len_is_5(t_stack *ts)
{
	int	a;
	int	pos;

	a = 0;
	pos = 0;
	while (a < 2)
	{
		pos = ft_get_pos_lower_number(ts->astack);
		ft_r_or_rr(ts, pos, 1);
		ft_print_op(ts, "pb");
		a++;
	}
	ft_len_is_3(ts);
	while (a > 0)
	{
		ft_print_op(ts, "pa");
		a--;
	}
	return (0);
}

void	ft_len_is_3_p2(t_stack *ts)
{
	t_stack	*stack;

	stack = ts->astack;
	if (stack->number < stack->next->number
		&& stack->next->number > stack->next->next->number
		&& stack->number < stack->next->next->number)
	{
		ft_print_op(ts, "sa");
		ft_print_op(ts, "ra");
	}
	if (stack->number < stack->next->number
		&& stack->next->number > stack->next->next->number
		&& stack->number > stack->next->next->number)
		ft_print_op(ts, "rra");
}

void	ft_len_is_3(t_stack *ts)
{
	t_stack	*stack;

	stack = ts->astack;
	if (stack->number > stack->next->number
		&& stack->next->number > stack->next->next->number
		&& stack->number > stack->next->next->number)
	{
		ft_print_op(ts, "sa");
		ft_print_op(ts, "rra");
	}
	if (stack->number > stack->next->number
		&& stack->next->number < stack->next->next->number
		&& stack->number < stack->next->next->number)
		ft_print_op(ts, "sa");
	if (stack->number > stack->next->number
		&& stack->next->number < stack->next->next->number
		&& stack->number > stack->next->next->number)
		ft_print_op(ts, "ra");
	ft_len_is_3_p2(ts);
}

int	ft_len_is_2(t_stack *ts)
{
	t_stack	*stack;

	stack = ts->astack;
	if (stack->number > stack->next->number)
		ft_print_op(ts, "sa");
	return (0);
}

int	ft_start_algo(t_stack *ts)
{
	if (ft_get_sort_stack(ts) == -1)
		return (-1);
	if (!ft_check_order(ts))
		return (0);
	else if (ts->lena == 2)
		ft_len_is_2(ts);
	else if (ts->lena == 3)
		ft_len_is_3(ts);
	else if (ts->lena == 5)
		ft_len_is_5(ts);
	else if (ts->lena == 100 || ts->lena == 500)
		ft_len_is_big(ts);
	else
		ft_len_is_else(ts);
	return (0);
}
