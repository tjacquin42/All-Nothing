# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckupfers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/18 22:43:46 by ckupfers          #+#    #+#              #
#    Updated: 2015/11/04 20:25:58 by ckupfers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat

FLAGS = -Wall -Werror -Wextra

SOURCE = main.c

all: $(NAME)

$(NAME):
		gcc -c $(FLAGS) $(SOURCE)
		gcc -o $(NAME) main.o

clean: 
	rm -f main.o

fclean: clean
	rm -f $(NAME)

re: fclean all
