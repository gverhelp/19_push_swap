/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_get_lower_number(t_stack *ts, t_stack *mystack)
{
    int     count;
    int     min;
    int     pos;
    t_stack *stack;

    count = 0;
    pos = 0;
    min = mystack->number;
    stack = ts->astack;
    while (stack)
    {
        if (min > stack->number)
        {
            min = stack->number;
            pos = count;
        }
        count++;
        stack = stack->next;
    }
    return (count);
}

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
