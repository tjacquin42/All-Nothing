NAME = fdf

SRC = srcs/main.c \
	  srcs/mat_rot.c \
	  srcs/pixel_puter.c \
	  srcs/print.c \
	  srcs/errors.c \

SRCO = main.o \
	   mat_rot.o \
	   pixel_puter.o \
	   print.o \
	   errors.o \


INCLUDE = includes/fdf.h

FLAGS = -Wall -Wextra -Werror

$(NAME):
	gcc $(FLAGS) -I $(INCLUDE) -c $(SRC)
	gcc $(SRCO) -o $(NAME)

all: $(NAME)

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
