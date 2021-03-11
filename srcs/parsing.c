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
		if (!ft_strcmp(set[a], str))
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

int		ft_parse(int argc, char **argv, t_stack *ts)
{
	int		a;

	a = 1;
	while (a < argc)
	{
		if (ft_youanumber(argv[a]) == -1 || ft_check_dupli(argv[a], argv) == -1)
			return (-1);
		if (ft_push_stack(&ts->astack, ft_atoi(argv[a])) == -1)
			return (-1);
		a++;
	}


//	ft_push_stack(&ts->bstack, 20);    //// to do some tests
//	ft_push_stack(&ts->bstack, 7);


///////////////////////////////////     Afficher le stack a
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
	return (0);
}






//	ts->firsta = ts->astack;
//	while (ts->astack)
//	{
//		printf("%d\n", ts->astack->number);
//		ts->astack = ts->astack->next;
//	}
//	ts->astack = ts->firsta;