# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckupfers <ckupfers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/27 18:09:49 by ckupfers          #+#    #+#              #
#    Updated: 2015/12/27 18:46:51 by ckupfers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail

SRC = ft_tail.c ft_utils.c

INCLUDES = ft_util.h

OBJ = ft_tail.o ft_utils.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) $(INCLUDES)
	gcc -o $(NAME) $(OBJ)
	rm -f ft_util.h.gch

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
