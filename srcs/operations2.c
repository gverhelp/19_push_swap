/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_rotate2(t_stack *ts)
{
	t_stack	*top;
	t_stack	*bot;

	if (!ts->bstack)
		return (-1);
	if (!ts->bstack->next)
		return (0);
	top = ts->bstack;
	bot = ft_get_last_elem(ts->bstack);
	ts->bstack = top->next;
	top->next = NULL;
	bot->next = top;
	return (0);
}

int	ft_rev_rotate2(t_stack *ts)
{
	t_stack	*bot;
	t_stack	*before_bot;

	if (!ts->bstack)
		return (-1);
	if (!ts->bstack->next)
		return (0);
	bot = ft_get_last_elem(ts->bstack);
	before_bot = ft_get_before_last_elem(ts->bstack);
	before_bot->next = NULL;
	bot->next = ts->bstack;
	ts->bstack = bot;
	return (0);
}
