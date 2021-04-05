/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_compare_hold(t_stack *ts)
{
    int a;
    int lena;
    int holdsecond;
    int countsec;

    a = 0;
    lena = ts->lena;
    countsec = 0;
    holdsecond = ts->holdsecond;
    while (a < ts->holdfirst)
        a++;
    while (lena > holdsecond)
    {
        countsec++;
        lena--;
    }
    if (a > countsec)
        ft_r_or_rr(ts, ts->holdsecond, 1);
    else
        ft_r_or_rr(ts, ts->holdfirst, 1);
    ft_print_op(ts, "pb");
    return (0);
}

int ft_get_hold_second(t_stack *ts, int start, int end)
{
    int len;
    int tmp;
    int *stackintab;

    len = ts->lena - 1;
    tmp = start;
    if (!(stackintab = ft_get_mystack_in_tab(ts->astack)))
        return (-1);
    while (len >= 0)
    {
        tmp = start;
        while (tmp <= end)
        {
            if (stackintab[len] == ts->sortedstack[tmp])
            {
                ts->holdsecond = len + 1;
                free(stackintab);
                return (0);
            }
            tmp++;
        }
        len--;
    }
    free(stackintab);
    return (-1);
}

int ft_get_hold_first(t_stack *ts, int start, int end)
{
    int     pos;
    int     tmp;
    t_stack *stack;

    pos = 0;
    stack = ts->astack;
    tmp = start;
    while (stack)
    {
        tmp = start;
        while (tmp <= end)
        {
            if (stack->number == ts->sortedstack[tmp])
            {
                ts->holdfirst = pos + 1;
                return (0);
            }
            tmp++;
        }
        stack = stack->next;
        pos++;
    }
    return (-1);
}

int ft_first_or_second(t_stack *ts, int start, int end)
{
    int tmp;

    tmp = start;
    while (tmp <= end)
    {
        ft_get_hold_first(ts, start, end);
        ft_get_hold_second(ts, start, end);
        ft_compare_hold(ts);
        tmp++;
    }
    return (0);
}
