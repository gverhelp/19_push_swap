/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_len_is_500(t_stack *ts)
{
    (void)ts;
    return (0);
}

int ft_len_is_100(t_stack *ts)
{
    int count;
    t_stack *stack;

    count = 0;
    stack = ts->astack;
    while (stack)
    {
        if (count >= 0 && count <= 19)
            ft_first_or_second(ts, 0, 19);
/*        if (count >= 20 && count <= 39)
            ft_first_or_second(ts, 20, 39);
        if (count >= 40 && count <= 59)
            ft_first_or_second(ts, 40, 59);
        if (count >= 60 && count <= 79)
            ft_first_or_second(ts, 60, 79);
        if (count >= 80 && count <= 99)
            ft_first_or_second(ts, 80, 99); */
        count++;
        stack = stack->next;
    }
    return (0);
}

int ft_len_is_big(t_stack *ts)
{
    if (ts->lena == 20)
    {
        ts->nbchunks = 5;
        ft_len_is_100(ts);
    }
    if (ts->lena == 500)
    {
        ts->nbchunks = 11;
        ft_len_is_500(ts);
    }
    return (0);
}

/*
int ft_fill_my_chunk(t_stack *ts, int chunk, int len)
{
    int a;

    a = 0;
    write(1, "OK\n", 3);
    while (a < len)
    {
        ts->chunks[chunk][a] = ts->sortedstack[a];
        a++;
    }
    write(1, "OK2\n", 4);
    a = 0;
    while (a < len)
    {
//        printf("chunk : %d\n", ts->chunks[0][a]);
        a++;
    }
    return (0);
}

int ft_get_my_chunks(t_stack *ts, int chunk, int len)
{
    int a;

    a = 0;
//    if (!(ts->chunks = malloc(sizeof(int*) * chunk)))
//        return (-1);
    while (a < chunk)
    {
        ft_fill_my_chunk(ts, a, len);
        a++;
    }
    return (0);
}
*/