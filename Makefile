NAME = push_swap
SRC = main.c list_operations1.c list_operations2.c list_creation_destruction.c hard_code_3.c init.c utils.c order_6.c
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	gcc -fsanitize=address -g3 $(OBJ) -o push_swap
all: $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re