/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int     ft_check_order(t_stack *ts)
{
    t_stack *stack;

    stack = ts->astack;
    if (ts->bstack)
        return (-1);
    while (stack && stack->next)
    {
        if (stack->number > stack->next->number)
            return (-1);
        stack = stack->next;
    }
    return (0);
}

t_stack	*ft_bottom_stack(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_before_bottom_stack(t_stack *stack)
{
	while (stack && stack->next->next)
		stack = stack->next;
	return (stack);
}