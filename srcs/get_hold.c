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

int ft_check_stackb(t_stack *ts)
{
    (void)ts;  
    return (0);
}

int ft_compare_hold(t_stack *ts)
{
    int a;
    int b;
    int tmp;

    a = 0;
    b = 0;
    tmp = ts->holdsecond;
    while (a < ts->holdfirst)
        a++;
    while (b < tmp)
        tmp--;
    if (a > tmp)
        ft_r_or_rr(ts, ts->holdsecond, 1);
    else
        ft_r_or_rr(ts, ts->holdfirst, 1);
    ft_check_stackb(ts);
    return (0);
}

int ft_get_hold(t_stack *ts, int stacknumber, int start, int end)
{
    while (start < end)
    {
        if (stacknumber == ts->sortedstack[start])
            return (0);
        start++;
    }
    return (-1);
}

int ft_first_or_second(t_stack *ts, int start, int end)
{
    int *stackintab;
    int len;
    t_stack *stack;

    len = 0;
    stack = ts->astack;
    while (stack)
    {
        if (ft_get_hold(ts, stack->number, start, end) != -1)
        {
            ts->holdfirst = len;
            break ;
        }
        stack = stack->next;
        len++;
    }
    if (!(stackintab = ft_get_mystack_in_tab(ts->astack)))
        return (-1);
    len = ts->lena;
    while (len)
    {
        if (ft_get_hold(ts, stackintab[len], start, end) != -1)
        {
            ts->holdsecond = len;
            break ;
        }
        len--;
    }
    ft_compare_hold(ts);
    return (0);
}