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
    if (!(newstack = malloc(len * sizeof(int))))
        return (NULL);
    len = 0;
    while (mystack)
    {
        newstack[len] = mystack->number;
//        printf("stacknumber : %d\n", newstack[len]);
        mystack = mystack->next;
        len++;
    }
    return (newstack);
}

int ft_get_higher_number(t_stack *mystack)
{
    int higher;

    higher = mystack->number;
    while (mystack)
    {
        if (higher < mystack->number)
            higher = mystack->number;
        mystack = mystack->next;
    }
    return (higher);
}

int ft_get_pos_higher_number(t_stack *mystack)
{
    int     count;
    int     max;
    int     pos;
    t_stack *stack;

    count = 1;
    pos = 0;
    max = mystack->number;
    stack = mystack;
    while (stack)
    {
        if (max < stack->number)
        {
            max = stack->number;
            pos = count;
        }
        count++;
        stack = stack->next;
    }
    return (pos);
}

int ft_get_lower_number(t_stack *mystack)
{
    int lower;
    t_stack *stack;

    lower = mystack->number;
    stack = mystack;
    while (stack)
    {
        if (lower > stack->number)
            lower = stack->number;
        stack = stack->next;
    }
    return (lower);
}

int ft_get_pos_lower_number(t_stack *mystack)
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
