/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_or_rra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:29:52 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 14:29:57 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_ra_or_rra2(t_stack *ts, int pos, t_stack **stack)
{
    
    return (0);
}


int	ft_ra_or_rra(t_stack *ts, int pos, int wichstack)
{
	if (wichstack == 1)
		ft_ra_or_rra2(ts, pos, &ts->astack);
	if (wichstack == 2)
		ft_ra_or_rra2(ts, pos, &ts->bstack);	
	return (0);
}