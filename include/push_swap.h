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
	char	*line;
	t_stack	*next;
	t_stack	*astack;
	t_stack	*bstack;
	t_stack	*firsta;
	t_stack	*firstb;
};

////////////// Parsing ///////////////

int		ft_check_dupli(char *str, char **set);
int		ft_youanumber(char *str);
int		ft_parse(int argc, char **argv, t_stack *ts);

/////////// Change stack //////////////

void	ft_stack_add_back(t_stack **alst, t_stack *new);
t_stack	*ft_new_elem(int number);
int		ft_push_stack(t_stack **stack, int newnumber);
int     ft_pop_stack(t_stack **stack);
t_stack	*ft_bottom_stack(t_stack *stack);
t_stack	*ft_before_bottom_stack(t_stack *stack);
int		ft_delete_stack(t_stack **stack);

//////////// Operations //////////////

int     ft_swap(t_stack *ts, int a);
int     ft_push(t_stack *ts, int a);
int     ft_rotate(t_stack *ts, int a);
int     ft_rev_rotate(t_stack *ts, int a);

//////////// Manip stack ////////////

int     ft_check_order(t_stack *ts);
t_stack	*ft_get_last_elem(t_stack *stack);
t_stack	*ft_get_before_last_elem(t_stack *stack);

///////// Push_swap_algo ////////////

int ft_start_algo();

/////////// Print operations /////////////

int		ft_print_op(char *str);

////////////// Utils ////////////////

void	ft_init_struct(t_stack *ts);
void	ft_exit(t_stack *ts, char *str, int fd);

#endif
