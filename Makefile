CC = gcc 
SRCS = main.c operations.c push_swap_utils.c sort100element.c creat_stack.c sort5element.c handle_erros.c sort_helper.c sort3element.c free.c ft_split.c ft_strdup.c ft_strlen.c util_functions.c operation_util.c
NAME = push_swap
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
%.o:%.c *.h
	$(CC) $(CFLAGS) -c $< -o $@
all: *.h
	@$(MAKE) $(NAME)
$(NAME): $(OBJS) 
	$(CC) $(OBJS) $(INC) -o $(NAME)
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all