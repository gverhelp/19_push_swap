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

int	ft_len_is_500(t_stack *ts)
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

int	ft_len_is_100(t_stack *ts)
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

int	ft_len_is_else(t_stack *ts)
{
	while (ts->lena)
	{
		ft_r_or_rr(ts, ft_get_pos_lower_number(ts->astack), 1);
		ft_print_op(ts, "pb");
	}
	while (ts->lenb)
		ft_print_op(ts, "pa");
	return (0);
}

int	ft_len_is_big(t_stack *ts)
{
	if (ts->lena == 100)
		ft_len_is_100(ts);
	if (ts->lena == 500)
		ft_len_is_500(ts);
	return (0);
}
