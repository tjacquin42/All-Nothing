# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchristo <marvin@42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:35:46 by dchristo          #+#    #+#              #
#    Updated: 2016/09/10 23:14:59 by dchristo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
PATH_INC = ./libft/

CC = gcc

CFLAGS	= -Wall -Wextra -Werror -O3 -Ofast

SRC = $(shell ls | grep "\.c")

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	@echo "\033[0m";
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJS) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "\033[1;5;1;36m";
	@echo "+-------------------------------------+";
	@echo "|  ______              _   _       _  |";
	@echo "| |  ____|            | | ( )     | | |";
	@echo "| | |__ _ __ __ _  ___| |_|/  ___ | | |";
	@echo "| |  __| '__/ _\` |/ __| __|  / _ \| | |";
	@echo "| | |  | | | (_| | (__| |_  | (_) | | |";
	@echo "| |_|  |_|  \__,_|\___|\__|  \___/|_| |";
	@echo "|                                     |";
	@echo "+-------------------------by dchristo-+";
	@echo "\033[0m";


.PHONY: clean fclean re all

clean:
	make -C libft/ clean
	rm -rf $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
