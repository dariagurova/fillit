# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/19 09:27:38 by dgurova           #+#    #+#              #
#    Updated: 2017/09/19 09:27:43 by dgurova          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILES = srcs/ft_readfile.c \
		srcs/solver.c \
		srcs/ft_mino.c \
		srcs/ft_helper.c \
		srcs/ft_functions.c
INCLUDES = includes/
OBJECTS = $(FILES:srcs/%.c=./%.o)
LIBFT = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT)
	@gcc -c $(FLAGS) main.c $(FILES) -I$(INCLUDES) -I./libft
	@gcc -o $(NAME) $(FLAGS) $(OBJECTS) $(LIBFT) main.o -I./libft -I$(INCLUDES)

$(LIBFT):
	@make -C ./libft

clean:
	@make clean -C ./libft
	@/bin/rm -f $(OBJECTS) main.o

fclean: clean
	@make fclean -C ./libft
	@/bin/rm -f $(NAME)

re: fclean all