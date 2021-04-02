/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_or_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:29:52 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 14:29:57 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_do_rr(t_stack *ts, int pos, int wichstack)
{
	if (wichstack == 1)
	{
		while (pos <= ts->lena)
		{
			ft_print_op(ts, "rra");
			pos++;
		}
	}
	if (wichstack == 2)
	{
		while (pos <= ts->lenb)
		{
			ft_print_op(ts, "rrb");
			pos++;
		}
	}
}

void	ft_do_r(t_stack *ts, int pos, int wichstack)
{
	while (pos > 1)
	{
		if (wichstack == 1)
			ft_print_op(ts, "ra");
		else
			ft_print_op(ts, "rb");
		pos--;
	}
}

int 	ft_r_or_rr2(t_stack *ts, int pos, int wichstack)
{
	if (wichstack == 1)
	{
		if (pos > (ts->lena / 2))
			ft_do_rr(ts, pos, 1);
		else
			ft_do_r(ts, pos, 1);
	}
	if (wichstack == 2)
	{
		if (pos > (ts->lenb / 2))
			ft_do_rr(ts, pos, 2);
		else
			ft_do_r(ts, pos, 2);
	}
    return (0);
}


int		ft_r_or_rr(t_stack *ts, int pos, int wichstack)
{
	if (wichstack == 1)
		ft_r_or_rr2(ts, pos, wichstack);
	if (wichstack == 2)
		ft_r_or_rr2(ts, pos, wichstack);	
	return (0);
}