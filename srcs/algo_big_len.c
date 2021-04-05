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
    ft_first_or_second(ts, 0, 44);
    ft_first_or_second(ts, 45, 89);
    ft_first_or_second(ts, 90, 134);
    ft_first_or_second(ts, 135, 179);
    ft_first_or_second(ts, 180, 224);
    ft_first_or_second(ts, 225, 269);
    ft_first_or_second(ts, 270, 314);
    ft_first_or_second(ts, 315, 359);
    ft_first_or_second(ts, 360, 404);
    ft_first_or_second(ts, 405, 449);
    ft_first_or_second(ts, 450, 499);
    while (ts->lenb)
    {
        ft_r_or_rr(ts, ft_get_pos_higher_number(ts->bstack), 2);
        ft_print_op(ts, "pa");
    }
    return (0);
}

int ft_len_is_100(t_stack *ts)
{
    ft_first_or_second(ts, 0, 19);
    ft_first_or_second(ts, 20, 39);
    ft_first_or_second(ts, 40, 59);
    ft_first_or_second(ts, 60, 79);
    ft_first_or_second(ts, 80, 99);
    while (ts->lenb)
    {
        ft_r_or_rr(ts, ft_get_pos_higher_number(ts->bstack), 2);
        ft_print_op(ts, "pa");
    }
    return (0);
}

int ft_len_is_big(t_stack *ts)
{
    if (ts->lena == 100)
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