NAME = fdf

SRC = srcs/main.c \

SRCO = main.o \

INCLUDE = fdf.h \

FLAGS = -Wall -Wextra -Werror

$(NAME):
	make -C libft/
	gcc $(FLAGS) -I $(INCLUDE) -c $(SRC)
	gcc $(SRCO) -o $(NAME) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
