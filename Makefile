NAME = push_swap
SRC = main.c list_operations1.c list_operations2.c list_creation_destruction.c executer.c init.c utils.c order_n.c hardcode.c inserter.c
CFLAGS = -Wall -Wextra -Werror -g3
RM = /bin/rm -rf
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	gcc $(OBJ) -o push_swap
all: $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re