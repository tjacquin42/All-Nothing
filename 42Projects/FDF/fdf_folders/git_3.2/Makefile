NAME = fdf

SRC = srcs/main.c \
	  srcs/mat_rot.c \
	  srcs/pixel_puter.c \
	  srcs/print_errors.c \
	  srcs/events_script.c \

SRCO = main.o \
	   mat_rot.o \
	   pixel_puter.o \
	   print_errors.o \
	   events_script.o \


INCLUDE = includes/fdf.h \

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
