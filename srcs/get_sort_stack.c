/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:29:52 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 14:29:57 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_true_swap(int **tab, int a, int b)
{
	int	tmp;

	tmp = (*tab)[a];
	(*tab)[a] = (*tab)[b];
	(*tab)[b] = tmp;
}

int	ft_get_sort_stack2(t_stack *ts)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < ts->lena - 1)
	{
		b = a + 1;
		while (b < ts->lena)
		{
			if (ts->sortedstack[a] > ts->sortedstack[b])
				ft_true_swap(&ts->sortedstack, a, b);
			b++;
		}
		a++;
	}
	return (0);
}

int	ft_get_sort_stack(t_stack *ts)
{
	int		a;
	t_stack	*stack;

	a = 0;
	stack = ts->astack;
	ts->sortedstack = malloc(ts->lena * sizeof(int));
	if (!ts->sortedstack)
		return (-1);
	while (stack)
	{
		ts->sortedstack[a] = stack->number;
		stack = stack->next;
		a++;
	}
	return (ft_get_sort_stack2(ts));
}
