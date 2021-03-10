/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:53:37 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 17:52:10 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_stack t_stack;

struct s_stack
{
	int		number;
	t_stack	*next;
	t_stack	*astack;
	t_stack	*bstack;
//	t_stack	*firsta;
};

int     ft_swap(t_stack *ts);
int     ft_push(t_stack *ts);
int     ft_rotate(t_stack *ts);
int     ft_rev_rotate(t_stack *ts);

#endif
