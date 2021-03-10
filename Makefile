SRC             =       oprations.c \

SRC_DIR         =       srcs/
SRC             =       $(addprefix $(SRC_DIR), $(SRC_NAMES))
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
		LFT             =       -L./libft -lft
endif

CC                      =       gcc -g -Wall -Wextra -Werror -I./libft/include/ -I./include/
RM                      =       rm -f
AR                      =       ar -rc

all: libft_all $(CHECKER) $(PUSH_SWAP)
$(CHECKER): $(OBJ) $(SRC_DIR)$(CHECKER).o $(LIBFT)
	$(CC) $(FLAGS) -o $(CHECKER) $(OBJ) $(SRC_DIR)$(CHECKER).o $(LFT)

$(PUSH_SWAP): $(OBJ) $(SRC_DIR)$(PUSH_SWAP).o $(LIBFT)
	$(CC) $(FLAGS) -o $(PUSH_SWAP) $(OBJ) $(SRC_DIR)$(PUSH_SWAP).o $(LFT)

clean: libft_clean
	cd libft/ && make $@
	$(RM) $(OBJ)
	$(RM) $(SRC_DIR)$(CHECKER).o
	$(RM) $(SRC_DIR)$(PUSH_SWAP).o

fclean:		libft_fclean clean
	make fclean -C ./libft
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