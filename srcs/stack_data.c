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

int *ft_get_mystack_in_tab(t_stack *mystack)
{
    int len;
    int *newstack;
    t_stack *firstelem;
    
    len = 0;
    firstelem = mystack;
    while (mystack)
    {
        len++;
        mystack = mystack->next;
    }
    mystack = firstelem;
    if (!(newstack = malloc(sizeof(int) * len)))
        return (NULL);
    len = 0;
    while (mystack)
    {
        newstack[len] = mystack->number;
        mystack = mystack->next;
        len++;
    }
    return (newstack);
}

/*
int *ft_reverse_list(int *reversestack, int len)
{
    int a;
    int *reverselist;

    a = 0;
    reverselist = NULL;
    while (len > 0)
    {
        reverselist[a] = reversestack[len];
        a++;
        len--;
    }
    return (reverselist);
}

int *ft_get_stack_reverse(t_stack *ts, t_stack *mystack)
{
    int a;
    int len;
    int *reversestack;
    t_stack *firstelem;

    len = 0;
    a = 0;
    firstelem = mystack;
    while (mystack)
    {
        len++;
        mystack = mystack->next;
    }
    mystack = firstelem;
    if (!(reversestack = malloc(sizeof(int) * len)))
        return (-1);
    while (mystack)
    {
        reversestack[a] = mystack->number;
        mystack = mystack->next;
        len++;
    }
    return (ft_reverse_list(reversestack, len));
}
*/
int ft_get_lower_number(t_stack *mystack)
{
    int     count;
    int     min;
    int     pos;
    t_stack *stack;

    count = 1;
    pos = 0;
    min = mystack->number;
    stack = mystack;
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
    return (pos);
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
