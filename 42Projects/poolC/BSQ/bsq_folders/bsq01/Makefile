# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/06 16:02:08 by tjacquin          #+#    #+#              #
#    Updated: 2016/02/06 18:38:11 by tjacquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = sources/check.c \
	  sources/ft_strlen.c \
	  sources/ft_strsub.c \
	  sources/ft_strjoin.c \
	  sources/ft_strdup.c

SRCO = check.o \
	   ft_strlen.o \
	   ft_strsub.o \
	   ft_strjoin.o \
	   ft_strdup.o

INCLUDE = ft.h

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
