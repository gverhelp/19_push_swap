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

void	ft_init_struct(t_push *tp)
{
	tp->astack = NULL;
	tp->bstack = NULL;
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

int		ft_parse(int argc, char **argv, t_push *tp)
{
	int	a;

	a = 1;
	while (a < argc)
	{
		if (ft_youanumber(argv[a]) == -1 || ft_check_dupli(argv[a], argv) == -1)
			return (-1);
		ft_lstadd_back(&tp->astack, ft_lstnew(argv[a]));
		a++;
	}
	tp->firsta = tp->astack;
	return (0);
}

int		main(int argc, char **argv)
{
	t_push	tp;
	ft_init_struct(&tp);
	if (argc > 1)
	{
		if (ft_parse(argc, argv, &tp) == -1)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
	}
	return (0);
}









//	while (tp->astack)
//	{
//		printf("%s\n", tp->astack->content);
//		tp->astack = tp->astack->next;
//	}
