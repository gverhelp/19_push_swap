/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_stack_add_back(t_stack **alst, t_stack *new)
{
	t_stack *lst;

	lst = *alst;
	if (*alst)
	{
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = new;
	}
	else
		*alst = new;
}

t_stack	*ft_new_elem(int newnumber)
{
	t_stack *lst;

	lst = malloc(sizeof(t_stack));
	if (lst == 0)
		return (0);
	lst->number = newnumber;
	lst->next = NULL;
	return (lst);
}

int		ft_delete_stack(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	if (!*stack)
		return (-1);
	else
	{
		while (*stack)
		{
			tmp = *stack;
			*stack = (*stack)->next;
			free(tmp);
		}
	}
	return (0);
}
