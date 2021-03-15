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
	t_stack	ts;

	ft_init_struct(&ts);
	if (argc > 1)
	{
		if (ft_parse(argc, argv, &ts) == -1)
		{
//			printf("ici3\n");
			ft_exit(&ts, "Error", 2);
		}
	}
	ft_start_algo(&ts);


////////////////////////////////////////////////// Afficher stack a
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
/////////////////////////////////////////////////
	return (0);
}
