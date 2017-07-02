# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/14 16:31:00 by tjacquin          #+#    #+#              #
#    Updated: 2017/06/12 17:15:24 by tjacquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= wolf3d

SRC= ./srcs/main.c \
	 ./srcs/cube.c \
	 ./srcs/draw.c \
	 ./srcs/event.c \
	 ./srcs/move.c \
	 ./srcs/ray.c \

OBJ= ./main.o \
	 ./cube.o \
	 ./draw.o \
	 ./event.o \
	 ./move.o \
	 ./ray.o \

FLAGS= -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	@make -C libft/
	@gcc -c $(FLAGS) -I wolf.h $(SRC)
	@gcc $(OBJ) -o $(NAME) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "\033[1;1;1;34m <>""\033[0;33mW""\033[1;34m<>""\033[0;33mO""\033[1;34m<>""\033[0;33mL""\033[1;34m<>""\033[0;33mF""\033[1;34m<>""\033[0;3;33m3""\033[1;34m<>""\033[0;3;33mD""\033[1;34m<>"
	@echo "\033[1;34m<>""\033[0;3;33mC""\033[1;34m<>""\033[0;3;33mR""\033[1;34m<>""\033[0;3;33mE""\033[1;34m<>""\033[0;3;33mA""\033[1;34m<>""\033[0;3;33mT""\033[1;34m<>""\033[0;3;33mE""\033[1;34m<>""\033[0;3;33mD""\033[1;34m<>\n"

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)

re: fclean all
