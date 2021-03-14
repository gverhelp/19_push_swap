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

int		ft_print_operations()
{
	return (0);
}

int		main(int argc, char **argv)
{
	t_stack	ts;

	ft_init_struct(&ts);
	if (argc > 1)
	{
		if (ft_parse(argc, argv, &ts) == -1)
			ft_exit(&ts, "Error", 2);
	}
	ft_start_algo();
	return (0);
}
