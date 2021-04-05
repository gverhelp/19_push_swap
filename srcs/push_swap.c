/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		main(int argc, char **argv)
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
	if (ft_start_algo(&ts) == -1)
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
	free(ts.sortedstack);
	ft_delete_stack(&ts.astack);
	ft_delete_stack(&ts.bstack);
	return (0);
}
