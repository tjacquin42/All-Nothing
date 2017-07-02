# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/06 16:02:08 by tjacquin          #+#    #+#              #
#    Updated: 2016/02/18 03:15:23 by tjacquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = sources/check.c \
	  sources/ft_atoi.c \
	  sources/ft_strcat.c \
	  sources/ft_strcpy.c \
	  sources/ft_strsub.c \
	  sources/ft_strjoin.c \
	  sources/ft_strdup.c \
	  sources/ft_strlen.c \
	  sources/ft_putstr.c \
	  sources/superior.c \
	  sources/searchsave.c \
	  sources/searchtall.c \
	  sources/thisend.c \
	  sources/verifpar.c \
	  sources/standinput.c \
	  sources/verif.c \
	  sources/cross.c

SRCO = check.o \
	   ft_atoi.o \
	   ft_strcat.o \
	   ft_strcpy.o \
	   ft_strsub.o \
	   ft_strjoin.o \
	   ft_strdup.o \
	   ft_strlen.o \
	   ft_putstr.o \
	   superior.o \
	   searchsave.o \
	   searchtall.o \
	   thisend.o \
	   verifpar.o \
	   standinput.o \
	   verif.o \
	   cross.o

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
