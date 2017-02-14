# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/31 18:57:05 by tjacquin          #+#    #+#              #
#    Updated: 2015/11/01 20:26:47 by tjacquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr

SRC = fonctions.c \
	  do_sup.c \
	  eval_expr.c \
	  main.c

SRCO = fonctions.o \
	   do_sup.o \
	   eval_expr.o \
	   main.o

INCLUDE = ft_h.h

FLAGS = -Wall -Wextra -Werror

all = $(NAME)

$(NAME):
	gcc $(FLAGS) -I$(INCLUDE) -c $(SRC)
	gcc $(FLAGS) $(SRCO) -o $(NAME)

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
