CC = gcc 
SRCS = main.c operations.c push_swap_utils.c sort100element.c creat_stack.c
NAME = push_swap
OBJS = $(SRCS:.c=.o)
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