/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:53:37 by gverhelp          #+#    #+#             */
/*   Updated: 2021/04/07 17:49:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack	t_stack;

struct			s_stack
{
	int			number;
	int			lena;
	int			lenb;
	char		*line;
	int			*sortedstack;
	int			holdfirst;
	int			holdsecond;
	t_stack		*next;
	t_stack		*astack;
	t_stack		*bstack;
};

////////////// Parsing ///////////////

int				ft_check_dupli(char *str, char **set);
int				ft_youanumber(char *str);
int				ft_parse(char **stack, t_stack *ts);

/////////// Manage stack //////////////

void			ft_stack_add_back(t_stack **alst, t_stack *new);
t_stack			*ft_new_elem(int number);
int				ft_delete_stack(t_stack **stack);

//////////// Do operations ///////////

int				ft_what_operation(t_stack *ts);
int				ft_what_operation2(t_stack *ts);
void			ft_print_op(t_stack *ts, char *str);
void			ft_print_op2(t_stack *ts, char *str);

//////////// Operations //////////////

int				ft_swap(t_stack *ts, int a);
int				ft_push(t_stack *ts, int a);
int				ft_rotate(t_stack *ts, int a);
int				ft_rev_rotate(t_stack *ts, int a);

/////////// Operations 2 ////////////

int				ft_rotate2(t_stack *ts);
int				ft_rev_rotate2(t_stack *ts);

///////// Oprations Utils ////////////

int				ft_push_stack(t_stack **stack, int newnumber);
int				ft_pop_stack(t_stack **stack);
t_stack			*ft_get_last_elem(t_stack *stack);
t_stack			*ft_get_before_last_elem(t_stack *stack);

//////////// stack data ////////////

int				ft_check_order(t_stack *ts);
int				ft_get_lower_number(t_stack *mystack);
int				ft_get_pos_lower_number(t_stack *mystack);
int				ft_get_higher_number(t_stack *mystack);
int				ft_get_pos_higher_number(t_stack *mystack);

//////////// Stack data 2 ///////////

int				*ft_get_mystack_in_tab(t_stack *mystack);

///////////// ra or rra /////////////

int				ft_r_or_rr(t_stack *ts, int pos, int wichstack);
void			ft_do_r(t_stack *ts, int pos, int wichstack);
void			ft_do_rr(t_stack *ts, int pos, int wichstack);

///////// Push_swap_algo ////////////

int				ft_start_algo(t_stack *ts);
int				ft_len_is_2(t_stack *ts);
void			ft_len_is_3(t_stack *ts);
void			ft_len_is_3_p2(t_stack *ts);
int				ft_len_is_5(t_stack *ts);

/////////// Algo big len ////////////

int				ft_len_is_big(t_stack *ts);
int				ft_len_is_100(t_stack *ts);
int				ft_len_is_500(t_stack *ts);
int				ft_len_is_else(t_stack *ts);

//////////// Get hold //////////////

int				ft_first_or_second(t_stack *ts, int start, int end);
int				ft_get_hold_first(t_stack *ts, int start, int end);
int				ft_get_hold_second(t_stack *ts, int start, int end);
int				ft_compare_hold(t_stack *ts);

////////// get sort stack //////////

int				ft_get_sort_stack(t_stack *ts);
int				ft_get_sort_stack2(t_stack *ts);
void			ft_true_swap(int **tab, int a, int b);

////////////// Utils ////////////////

void			ft_init_struct(t_stack *ts);
void			ft_exit(t_stack *ts, char *str, int fd);
void			ft_free_tab(char **tab);

/////////// libft utils /////////////:

char			**ft_split(char const *s, char c);
void			ft_putendl_fd(char *s, int fd);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_putchar_fd(char c, int fd);

#endif
