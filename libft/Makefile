# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgurova <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/01 19:35:21 by dgurova           #+#    #+#              #
#    Updated: 2017/10/01 23:07:12 by dgurova          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = $(wildcard ./*.c)
BINS = $(patsubst ./%.c, %.o, $(SRCS))
FLAGS = -Wall -Wextra -Werror

.PHONY: re all clean fclean

%.o : 
	gcc -Iincludes $(FLAGS) -c $(SRCS)

all: $(NAME)

$(NAME): $(BINS)
	ar rc $(NAME) $(BINS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
