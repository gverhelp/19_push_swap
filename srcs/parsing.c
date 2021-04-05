/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ft_check_dupli(char *str, char **set)
{
	int a;
	int count;

	a = 0;
	count = 0;
	while (set[a])
	{
		if (ft_atoi(set[a]) == ft_atoi(str))
			count++;
		a++;
	}
	if (count >= 2)
		return (-1);
	return (0);
}

int		ft_youanumber(char *str)
{
	int	a;
	int	len;

	a = 0;
	len = 0;
	if (str[a] == '-')
		a++;
	len = ft_strlen(&str[a]);
	if (len > 10)
		return (-1);
	while (str[a])
	{
		if (!ft_isdigit(str[a]))
			return (-1);
		a++;
	}
	if (len == 10)
	{
		a = ft_atoi(str);
		if (a == 0 || a == -1)
			return (-1);
	}
	return (0);
}

int		ft_parse(char **stack, t_stack *ts)
{
	int		a;
	int		len;

	a = 0;
	len = 0;
	while (stack[len])
		len++;
	while (a < len)
	{
		if (ft_youanumber(stack[a]) == -1 || ft_check_dupli(stack[a], stack) == -1)
			return (-1);
		ft_stack_add_back(&ts->astack, ft_new_elem(ft_atoi(stack[a])));
		ts->lena++;
		a++;
	}
	ft_free_tab(stack);
/*///////////////////////////////////     Afficher le stack a
	ts->firsta = ts->astack;
	while (ts->astack)
	{
		printf("%d\n", ts->astack->number);
		ts->astack = ts->astack->next;
	}
	ts->astack = ts->firsta;
////////////////////////////////////   Afficher le stack b
	ts->firstb = ts->bstack;
	while (ts->bstack)
	{
		printf("%d\n", ts->bstack->number);
		ts->bstack = ts->bstack->next;
	}
	ts->bstack = ts->firstb;
*///////////////////////////////////
	return (0);
}