/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/04/07 17:19:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_init_struct(t_stack *ts)
{
	ts->astack = NULL;
	ts->bstack = NULL;
	ts->next = NULL;
	ts->number = 0;
	ts->lena = 0;
	ts->lenb = 0;
	ts->line = NULL;
	ts->sortedstack = NULL;
	ts->holdfirst = 0;
	ts->holdsecond = 0;
}

void	ft_exit(t_stack *ts, char *str, int fd)
{
	ft_putendl_fd(str, fd);
	free(ts->line);
	free(ts->sortedstack);
	ft_delete_stack(&ts->astack);
	ft_delete_stack(&ts->bstack);
	exit(0);
}

void	ft_free_tab(char **tab)
{
	int	a;

	a = 0;
	while (tab[a])
	{
		free(tab[a]);
		tab[a] = NULL;
		a++;
	}
	free(tab);
	tab = NULL;
}
