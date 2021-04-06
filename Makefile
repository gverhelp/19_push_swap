# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/12 12:18:47 by gverhelp          #+#    #+#              #
#    Updated: 2021/04/06 17:06:19 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  operations.c \
		operations2.c \
		operations_utils.c \
		do_operations.c \
		r_or_rr.c \
		push_swap_algo.c \
		algo_big_len.c \
		get_hold.c \
		manage_stack.c \
		get_sort_stack.c \
		parsing.c \
		stack_data.c \
		stack_data2.c \
		utils.c \
		libft_utils.c \
		libft_utils2.c \
		utils_gnl.c \
		utils_gnl2.c \
		utils_split.c \

SRC_DIR = srcs/
SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(SRC:%.c=%.o)
CHECKER = checker
PUSH_SWAP = push_swap
UNAME_S = $(shell uname -s)

CC = gcc -g -Wall -Wextra -Werror
RM = rm -f

all: $(CHECKER) $(PUSH_SWAP)
$(CHECKER): $(OBJ) $(SRC_DIR)$(CHECKER).o
	$(CC) -o $(CHECKER) $(OBJ) $(SRC_DIR)$(CHECKER).o

$(PUSH_SWAP): $(OBJ) $(SRC_DIR)$(PUSH_SWAP).o
	$(CC) -o $(PUSH_SWAP) $(OBJ) $(SRC_DIR)$(PUSH_SWAP).o

clean:
	$(RM) $(OBJ)
	$(RM) $(SRC_DIR)$(CHECKER).o
	$(RM) $(SRC_DIR)$(PUSH_SWAP).o

fclean: clean
	$(RM) $(CHECKER)
	$(RM) $(PUSH_SWAP)

re: fclean all

.PHONY: all clean fclean re