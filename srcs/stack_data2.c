/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_data2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*ft_get_mystack_in_tab(t_stack *mystack)
{
	int		len;
	int		*newstack;
	t_stack	*firstelem;

	len = 0;
	firstelem = mystack;
	while (mystack)
	{
		len++;
		mystack = mystack->next;
	}
	mystack = firstelem;
	newstack = malloc(len * sizeof(int));
	if (!newstack)
		return (NULL);
	len = 0;
	while (mystack)
	{
		newstack[len] = mystack->number;
		mystack = mystack->next;
		len++;
	}
	return (newstack);
}
