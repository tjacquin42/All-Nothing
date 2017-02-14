# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckupfers <ckupfers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/28 00:33:39 by ckupfers          #+#    #+#              #
#    Updated: 2016/01/02 14:15:45 by ckupfers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_hexdump

SRC = main.c ft_numchar.c ft_hexa.c print.c

OBJ = main.o ft_numchar.o ft_hexa.o print.o

INCLUDE = hexdump.h

FLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) $(INCLUDE)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f main.o ft_numchar.o ft_hexa.o print.o
	rm -f hexdump.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all
