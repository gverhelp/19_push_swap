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

void	ft_init_struct(t_stack *ts)
{
	ts->astack = NULL;
	ts->bstack = NULL;
}

t_stack	*ft_new_elem(int number)
{
	t_stack *lst;

	lst = malloc(sizeof(t_stack));
	if (lst == 0)
		return (0);
	lst->number = number;
	lst->next = NULL;
	return (lst);
}

void	ft_push_stack(t_stack **stack, int number)
{
	t_stack *first;

	first = ft_new_elem(number);
	first->next = *stack;
	*stack = first;
}

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
		ft_push_stack(&ts->astack, ft_atoi(argv[a]));
		a++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_stack	ts;
	ft_init_struct(&ts);
	if (argc > 1)
	{
		if (ft_parse(argc, argv, &ts) == -1)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
	}
	return (0);
}









//	while (ts->astack)
//	{
//		printf("%d\n", ts->astack->number);
//		ts->astack = ts->astack->next;
//	}
