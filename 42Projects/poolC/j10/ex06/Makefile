# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/03 02:28:29 by tjacquin          #+#    #+#              #
#    Updated: 2015/11/03 18:35:32 by tjacquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRC = fonctions.c \
	  do_op.c \
	  do_op2.c

SRCO = fonctions.o \
	   do_op.o \
	   do_op2.o

FLAGS = -Wall -Wextra -Werror

INCLUDES = includes.h

all = $(NAME)

$(NAME):
	gcc $(FLAGS) -I$(INCLUDES) -c $(SRC)
	gcc $(FLAGS) $(SRCO) -o $(NAME)

clean:
	/bin/rm -f $(SRCO)

fclean:
	/bin/rm -f $(NAME)

re: fclean all
