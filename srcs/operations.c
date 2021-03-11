/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int     ft_swap(t_stack *ts, int a)
{
    t_stack *stack;
    int     tmp;

    tmp = 0;
    if (a == 1)
        stack = ts->astack;
    if (a == 2)
        stack = ts->bstack;
    if (!stack || !stack->next)
        ft_exit("KO");
    tmp = stack->number;
    stack->number = stack->next->number;
    stack->next->number = tmp;
    return (0);
}

int     ft_push(t_stack *ts, int a)
{
    if (a == 1)
    {
        if (!ts->bstack)
            ft_exit("KO");
        ft_push_stack(&ts->astack, ts->bstack->number);
        ft_pop_stack(&ts->bstack);
    }
    if (a == 2)
    {
        if (!ts->astack)
            ft_exit("KO");
        ft_push_stack(&ts->bstack, ts->astack->number);
        ft_pop_stack(&ts->astack);
    }
    return (0);
}

int     ft_rotate(t_stack *ts, int a)
{
    t_stack *top;
    t_stack *bot;

    if (a == 1)
    {
        if (!ts->astack)
            ft_exit("KO");
        if (!ts->astack->next)                       ///// Demander si faire rotate avec un seul nombre dans le stack est possible
            return (0);
        top = ts->astack;
        bot = ft_bottom_stack(ts->astack);
        ts->astack = top->next;
        top->next = NULL;
        bot->next = top;
    }
    if (a == 2)
    {
        if (!ts->bstack)
            ft_exit("KO");
        if (!ts->bstack->next)
            return (0);
        top = ts->bstack;
        bot = ft_bottom_stack(ts->bstack);
        ts->bstack = top->next;
        top->next = NULL;
        bot->next = top;
    }
    return (0);
}

int     ft_rev_rotate(t_stack *ts, int a)
{
    t_stack *bot;
    t_stack *before_bot;

    if (a == 1)
    {
        if (!ts->astack)
            ft_exit("KO");
        if (!ts->astack->next)
            return (0);
        bot = ft_bottom_stack(ts->astack);
        before_bot = ft_before_bottom_stack(ts->astack);
        before_bot->next = NULL;
        bot->next = ts->astack;
        ts->astack = bot;
    }
    if (a == 2)
    {
        if (!ts->bstack)
            ft_exit("KO");
        if (!ts->bstack->next)
            return (0);
        bot = ft_bottom_stack(ts->bstack);
        before_bot = ft_before_bottom_stack(ts->bstack);
        before_bot->next = NULL;
        bot->next = ts->bstack;
        ts->bstack = bot;
    }
    return (0);
}
