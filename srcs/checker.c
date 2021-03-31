/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:29:52 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 14:29:57 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ft_what_operation2(t_stack *ts)
{
	if (!ft_strcmp(ts->line, "rr"))
	{
		if (ft_rotate(ts, 1) == -1 || ft_rotate(ts, 2) == -1)
			return (-1);
		return (0);
	}
	if (!ft_strcmp(ts->line, "rra"))
		return (ft_rev_rotate(ts, 1));
	if (!ft_strcmp(ts->line, "rrb"))
		return (ft_rev_rotate(ts, 2));
	if (!ft_strcmp(ts->line, "rrr"))
	{
		if (ft_rev_rotate(ts, 1) == -1 || ft_rev_rotate(ts, 2) == -1)
			return (-1);
		return (0);
	}
	return (-1);
}

int		ft_what_operation(t_stack *ts)
{
	if (!ft_strcmp(ts->line, "sa"))
		return (ft_swap(ts, 1));
	if (!ft_strcmp(ts->line, "sb"))
		return (ft_swap(ts, 2));
	if (!ft_strcmp(ts->line, "ss"))
	{
		if (ft_swap(ts, 1) == -1 || ft_swap(ts, 2) == -1)
			return (-1);
		return (0);
	}
	if (!ft_strcmp(ts->line, "pa"))
		return (ft_push(ts, 1));
	if (!ft_strcmp(ts->line, "pb"))
		return (ft_push(ts, 2));
	if (!ft_strcmp(ts->line, "ra"))
		return (ft_rotate(ts, 1));
	if (!ft_strcmp(ts->line, "rb"))
		return (ft_rotate(ts, 2));
	return (ft_what_operation2(ts));
}

int     main(int argc, char **argv)
{
	char	**stack;
    t_stack	ts;

	stack = NULL;
	ft_init_struct(&ts);
	if (argc != 2)
		return (0);
	if (argc == 2)
		stack = ft_split(argv[1], ' ');
	if (ft_parse(stack, &ts) == -1)
		ft_exit(&ts, "Error", 2);
	while (/*ft_check_order(&ts) == -1 &&*/ get_next_line(0, &ts.line) > 0)
	{
		if (ft_what_operation(&ts) == -1)
			ft_exit(&ts, "Error", 2);
/*////////////////////////////////////////////////// Afficher stack a
    	ts.firsta = ts.astack;
		while (ts.astack)
		{
			printf("stack a : %d\n", ts.astack->number);
			ts.astack = ts.astack->next;
		}
		ts.astack = ts.firsta;
////////////////////////////////////////////////// Afficher stack b
    	ts.firstb = ts.bstack;
		while (ts.bstack)
		{
			printf("stack b : %d\n", ts.bstack->number);
			ts.bstack = ts.bstack->next;
		}
		ts.bstack = ts.firstb;
*/////////////////////////////////////////////////
		free(ts.line);
	}
	free(ts.line);
	if (ft_check_order(&ts) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_delete_stack(&ts.astack);
	ft_delete_stack(&ts.bstack);
    return (0);
}