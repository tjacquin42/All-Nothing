# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/14 14:54:34 by tjacquin          #+#    #+#              #
#    Updated: 2017/03/14 15:42:42 by tjacquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fractol

SRC= ./srcs/main.c \
		./srcs/mandelbrot.c \
		./srcs/move.c \
		./srcs/events.c \
		./srcs/draw.c \
		./srcs/julia.c \
		./srcs/b_ship.c \
		./srcs/julio.c \
		./srcs/tricorn.c \
		./srcs/error.c \

OBJ= ./main.o \
		./mandelbrot.o \
		./move.o \
		./events.o \
		./draw.o \
		./julia.o \
		./b_ship.o \
		./julio.o \
		./tricorn.o \
		./error.o \

FLAGS= -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	@make -C libft/
	@gcc -c $(FLAGS) -I ./includes/fractol.h $(SRC)
	@gcc $(OBJ) -o $(NAME) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "\033[1;1;1;34m<>""\033[0;33mF""\033[1;34m<>""\033[0;33mR""\033[1;34m<>""\033[0;33mA""\033[1;34m<>""\033[0;33mC""\033[1;34m<>""\033[0;33mT""\033[1;34m<>""\033[0;33mO""\033[1;34m<>""\033[0;33mL""\033[1;34m<>"
	@echo "\033[1;34m<>""\033[0;3;33mC""\033[1;34m<>""\033[0;3;33mR""\033[1;34m<>""\033[0;3;33mE""\033[1;34m<>""\033[0;3;33mA""\033[1;34m<>""\033[0;3;33mT""\033[1;34m<>""\033[0;3;33mE""\033[1;34m<>""\033[0;3;33mD""\033[1;34m<>\n"

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)

re: fclean all
