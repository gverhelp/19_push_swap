/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:29:52 by gverhelp          #+#    #+#             */
/*   Updated: 2021/04/07 17:29:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	char	**stack;
	t_stack	ts;

	ft_init_struct(&ts);
	if (argc != 2)
		return (0);
	if (argc == 2)
		stack = ft_split(argv[1], ' ');
	if (ft_parse(stack, &ts) == -1)
		ft_exit(&ts, "Error", 2);
	while ((get_next_line(0, &ts.line)) > 0)
	{
		if (ft_what_operation(&ts) == -1)
			ft_exit(&ts, "Error", 2);
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
