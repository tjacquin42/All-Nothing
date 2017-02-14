# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/29 21:08:41 by tjacquin          #+#    #+#              #
#    Updated: 2015/11/03 19:47:52 by tjacquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCC = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c	\
	   ./srcs/ft_strlen.c ./srcs/ft_swap.c

SRCO = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

HEADER = ./includes/

all: $(NAME)

$(NAME):
	gcc -c $(SRCC)
	ar rc $(NAME) $(SRCO)

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean
	make
