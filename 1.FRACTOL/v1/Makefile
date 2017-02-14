# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/13 01:06:46 by tjacquin          #+#    #+#              #
#    Updated: 2017/02/14 12:50:52 by tjacquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = srcs/main.c \
	  srcs/error.c \
	  srcs/draw.c \
	  srcs/julia.c \
	  srcs/mandel.c \

SRCO = main.o \
	   error.o \
	   draw.o \
	   julia.o \
	   mandel.o \

INCLUDE = includes/fractol.h \

COMPILE = -lm -L Libft/ -lft -lmlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror

$(NAME):
	make -C libft/
	gcc $(FLAGS) -I $(INCLUDE) -c $(SRC)
	gcc $(SRCO) -o $(NAME) $(COMPILE)
	/bin/rm *.o

all: $(NAME)

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
