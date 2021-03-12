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

int		what_operation(char *str, t_stack *ts)
{
	if (!ft_strcmp(str, "sa"))
		return (ft_swap(ts, 1));
	if (!ft_strcmp(str, "sb"))
		return (ft_swap(ts, 2));
	if (!ft_strcmp(str, "ss"))
	{
		if (ft_swap(ts, 1) == -1 || ft_swap(ts, 2) == -1)
			return (-1);
		return (0);
	}
	if (!ft_strcmp(str, "pa"))
		return (ft_push(ts, 1));
	if (!ft_strcmp(str, "pb"))
		return (ft_push(ts, 2));
	if (!ft_strcmp(str, "ra"))
		return (ft_rotate(ts, 1));
	if (!ft_strcmp(str, "rb"))
		return (ft_rotate(ts, 2));
	if (!ft_strcmp(str, "rr"))
	{
		if (ft_rotate(ts, 1) == -1 || ft_rotate(ts, 2) == -1)
			return (-1);
		return (0);
	}
	if (!ft_strcmp(str, "rra"))
		return (ft_rev_rotate(ts, 1));
	if (!ft_strcmp(str, "rrb"))
		return (ft_rev_rotate(ts, 2));
	if (!ft_strcmp(str, "rrr"))
	{
		if (ft_rev_rotate(ts, 1) == -1 || ft_rev_rotate(ts, 2) == -1)
			return (-1);
		return (0);
	}
	return (-1);
}

int     main(int argc, char **argv)
{
    t_stack	ts;

	ft_init_struct(&ts);
	if (argc > 1)
	{
		if (ft_parse(argc, argv, &ts) == -1)
			ft_exit(&ts, "Error", 2);
	}
	while (/*ft_check_order(&ts) == -1 &&*/ get_next_line(0, &ts.line) > 0)
	{
		if (what_operation(ts.line, &ts) == -1)
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
//	free(st.line);
	if (ft_check_order(&ts) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_delete_all_stack(&ts.astack);
	ft_delete_all_stack(&ts.bstack);
    return (0);
}