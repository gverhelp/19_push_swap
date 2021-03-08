SRCS = *.c
CHECKER = checker
PUSH_SWAP = push_swap
OBJS = ${SRCS:.c=.o}
LIBFT = libft/libft.a
LIBFTPATH = ./libft
CC = gcc -g -Wall -Wextra -Werror
FLAGS = -I ./include/ -L
LIBFLAGS = -I ./libft -L ./libft -L . ./libft/*.c
RM = rm -f

all: libft_all ${CHECKER} ${PUSH_SWAP}
$(CHECKER): ${OBJS}
			$(CC) $(LIBFLAGS) $(LIBFT) $(FLAGS) $(OBJS) -o $@
$(PUSH_SWAP): ${OBJS}
			$(CC) $(LIBFLAGS) $(LIBFT) $(FLAGS) $(OBJS) -o $@

clean: libft_clean
	${RM} ${OBJS}

flcean: libft_fclean clean
	${RM} ${CHECKER}
	${RM} ${PUSH_SWAP}

re: fclean all

libft_all:
	make -C $(LIBFTPATH) all

libft_clean:
	make -C $(LIBFTPATH) clean

libft_fclean:
	make -C $(LIBFTPATH) fclean
	$(RM) $(LIBFT)

.PHONY: all fclean clean re