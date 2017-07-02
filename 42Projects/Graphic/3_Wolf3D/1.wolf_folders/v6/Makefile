# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/12 20:44:36 by tjacquin          #+#    #+#              #
#    Updated: 2017/06/12 20:44:40 by tjacquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= wolf3d

SRC= ./srcs/main.c \
	 ./srcs/event.c \
	 ./srcs/raycaster.c \
	 ./srcs/trace.c \
	 ./srcs/func.c \
	 ./srcs/move.c \

OBJ= ./main.o \
	 ./event.o \
	 ./raycaster.o \
	 ./trace.o \
	 ./func.o \
	 ./move.o \

FLAGS= -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	@make -C libft/
	@gcc -c $(FLAGS) -I ./includes/wolf3d.h $(SRC)
	@gcc $(OBJ) -o $(NAME) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "\033[32m$(NAME) is now ready to go!"

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@echo "\033[34mSuccessfully removed OBJ files"

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@echo "\033[31mEverything is cleaned UP"

re: fclean all
