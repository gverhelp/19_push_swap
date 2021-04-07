/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_push_stack(t_stack **stack, int newnumber)
{
	t_stack	*firststack;

	firststack = ft_new_elem(newnumber);
	if (!firststack)
		return (-1);
	firststack->next = *stack;
	*stack = firststack;
	return (0);
}

int	ft_pop_stack(t_stack **stack)
{
	t_stack	*del;

	if (!*stack)
		return (-1);
	del = *stack;
	*stack = (*stack)->next;
	free(del);
	return (0);
}

t_stack	*ft_get_last_elem(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_get_before_last_elem(t_stack *stack)
{
	while (stack && stack->next->next)
		stack = stack->next;
	return (stack);
}
