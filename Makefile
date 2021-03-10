# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 15:39:59 by gverhelp          #+#    #+#              #
#    Updated: 2021/03/08 17:43:28 by gverhelp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS             =       operations.c \
							change_list.c \
							parsing.c \
							utils.c \

SRC_DIR         =       srcs/
SRC             =       $(addprefix $(SRC_DIR), $(SRCS))
OBJ             =       $(SRC:%.c=%.o)

CHECKER         =       checker
PUSH_SWAP       =       push_swap


UNAME_S         =      $(shell uname -s)
LIBFT           =       libft/libft.a
LIBFTPATH       =		./libft
 

ifeq ($(UNAME_S), Darwin)
		LFT             =       $(LIBFT)
endif
ifeq ($(UNAME_S), Linux)
		LFT             =       -L$(LIBFTPATH) -lft
endif

CC                      =       gcc -g -Wall -Wextra -Werror -I./libft/include/ -I./include/
RM                      =       rm -f

all: libft_all $(CHECKER) $(PUSH_SWAP)
$(CHECKER): $(OBJ) $(SRC_DIR)$(CHECKER).o $(LIBFT)
	$(CC) -o $(CHECKER) $(OBJ) $(SRC_DIR)$(CHECKER).o $(LFT)

$(PUSH_SWAP): $(OBJ) $(SRC_DIR)$(PUSH_SWAP).o $(LIBFT)
	$(CC) -o $(PUSH_SWAP) $(OBJ) $(SRC_DIR)$(PUSH_SWAP).o $(LFT)

clean: libft_clean
	cd libft/ && make $@
	$(RM) $(OBJ)
	$(RM) $(SRC_DIR)$(CHECKER).o
	$(RM) $(SRC_DIR)$(PUSH_SWAP).o

fclean:		libft_fclean clean
	make fclean -C $(LIBFTPATH)
	$(RM) $(CHECKER)
	$(RM) $(PUSH_SWAP)

re: fclean all

libft_all:
	make -C $(LIBFTPATH) all

libft_clean:
	make -C $(LIBFTPATH) clean

libft_fclean:
	make -C $(LIBFTPATH) fclean
	$(RM) $(LIBFT)

.PHONY: all clean fclean re