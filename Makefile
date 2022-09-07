NAME = push_swap
UTILS_DIR = utils
SRC = main.c operations1.c operations2.c executer.c init.c order_n.c hardcode.c inserter.c move.c insert_fold.c fold_0.c \
	$(UTILS_DIR)/ft_split.c $(UTILS_DIR)/utils_lists1.c $(UTILS_DIR)/utils_lists2.c $(UTILS_DIR)/utils_math.c $(UTILS_DIR)/utils1.c $(UTILS_DIR)/utils2.c 
CFLAGS = -Wall -Wextra -Werror
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