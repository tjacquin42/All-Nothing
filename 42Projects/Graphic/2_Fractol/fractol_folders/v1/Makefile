# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/13 01:06:46 by tjacquin          #+#    #+#              #
#    Updated: 2017/02/23 16:43:27 by tjacquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = srcs/main.c \
	  srcs/error.c \
	  srcs/init.c \
	  srcs/julia.c \
	  srcs/mandel.c \
	  srcs/event.c \
	  srcs/square.c \

SRCO = main.o \
	   error.o \
	   init.o \
	   julia.o \
	   mandel.o \
	   event.o \
	   square.o \

INCLUDE = includes/fractol.h \

COMPILE = -lm -L libft -lft -lmlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror

$(NAME):
	@make -C libft/
	@echo "\033[1;1;1;30m";
	@gcc $(FLAGS) -I $(INCLUDE) -c $(SRC)
	@gcc $(SRCO) -o $(NAME) $(COMPILE)
	@echo "\033[1;1;1;34m<>""\033[0;33mF""\033[1;34m<>""\033[0;33mR""\033[1;34m<>""\033[0;33mA""\033[1;34m<>""\033[0;33mC""\033[1;34m<>""\033[0;33mT""\033[1;34m<>""\033[0;33mO""\033[1;34m<>""\033[0;33mL""\033[1;34m<>"
	@echo "\033[1;34m<>""\033[0;3;33mC""\033[1;34m<>""\033[0;3;33mR""\033[1;34m<>""\033[0;3;33mE""\033[1;34m<>""\033[0;3;33mA""\033[1;34m<>""\033[0;3;33mT""\033[1;34m<>""\033[0;3;33mE""\033[1;34m<>""\033[0;3;33mD""\033[1;34m<>\n"
	@/bin/rm *.o

all : $(NAME)

clean:
	@make -C libft/ clean
	@echo "\033[1;30m";
	@echo "\n\033[1;1;1;30m\n";
	@/bin/rm -f $(SRCO)

fclean:
	@make -C libft/ fclean
	@echo "\033[1;1;1;30m";
	@/bin/rm -f $(SRCO) $(NAME)

re: fclean all
