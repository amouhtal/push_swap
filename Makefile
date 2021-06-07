# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amouhtal <amouhtal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 14:46:27 by amouhtal          #+#    #+#              #
#    Updated: 2021/06/07 18:46:39 by amouhtal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc 
SRCS = main.c operations/operations.c operations/operation_util.c push_swap_utils.c  creat_stack.c \
	sortelement/sort5element.c handle_erros.c sort_helper.c sortelement/sort3element.c free.c ft_split.c\
	ft_strdup.c ft_strlen.c util_functions.c sortelement/sort100element.c
NAME = push_swap
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
%.o:%.c *.h
	$(CC) $(CFLAGS) -c $< -o $@
all: *.h
	@$(MAKE) $(NAME)
$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME)
clean:
	rm -rf *.o
	rm -rf operations/*.o
	rm -rf sortelement/*.o
fclean: clean
	rm -rf $(NAME)
re: fclean all