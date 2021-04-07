/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/04/07 18:04:50 by user42           ###   ########.fr       */
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
	if (ft_start_algo(&ts) == -1)
		ft_exit(&ts, "Error", 2);
	free(ts.sortedstack);
	ft_delete_stack(&ts.astack);
	ft_delete_stack(&ts.bstack);
	return (0);
}
