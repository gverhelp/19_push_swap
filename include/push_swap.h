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
	int		len;
	char	*line;
	int		*sortedstack;
	t_stack	*next;
	t_stack	*astack;
	t_stack	*bstack;

	t_stack	*firsta;
	t_stack	*firstb;
};

////////////// Parsing ///////////////

int		ft_check_dupli(char *str, char **set);
int		ft_youanumber(char *str);
int		ft_parse(char **argv, t_stack *ts);

/////////// Manage stack //////////////

void	ft_stack_add_back(t_stack **alst, t_stack *new);
t_stack	*ft_new_elem(int number);
int		ft_delete_stack(t_stack **stack);

//////////// Do operations ///////////

int		ft_what_operation(t_stack *ts);
int		ft_what_operation2(t_stack *ts);
void    ft_print_op(t_stack *ts, char *str);

//////////// Operations //////////////

int     ft_swap(t_stack *ts, int a);
int     ft_push(t_stack *ts, int a);
int     ft_rotate(t_stack *ts, int a);
int     ft_rev_rotate(t_stack *ts, int a);

///////// Oprations Utils ////////////

int		ft_push_stack(t_stack **stack, int newnumber);
int     ft_pop_stack(t_stack **stack);
t_stack	*ft_get_last_elem(t_stack *stack);
t_stack	*ft_get_before_last_elem(t_stack *stack);

//////////// stack data ////////////

int     ft_check_order(t_stack *ts);
int 	ft_get_lower_number(t_stack *ts, t_stack *mystack);

///////////// ra or rra /////////////

int	ft_ra_or_rra(t_stack *ts, int a, int wichstack);

///////// Push_swap_algo ////////////

int 	ft_start_algo(t_stack *ts);
int		ft_wich_algo(t_stack *ts);
int		ft_len_is_2(t_stack *ts);
int		ft_len_is_3(t_stack *ts);
int		ft_len_is_5(t_stack *ts);

//int		ft_ra_or_rra(t_stack *ts);
//int		ft_find_lower(t_stack *ts, int find);
//int		ft_do_rra(t_stack *ts, int pos);
//int		ft_do_ra(t_stack *ts, int pos);

////////// get sort stack //////////

int		ft_get_sort_stack(t_stack *ts);
int		ft_get_sort_stack2(t_stack *ts);
void	ft_true_swap(int **tab, int a, int b);

////////////// Utils ////////////////

void	ft_init_struct(t_stack *ts);
void	ft_exit(t_stack *ts, char *str, int fd);
void	ft_free_tab(char **tab);

#endif
