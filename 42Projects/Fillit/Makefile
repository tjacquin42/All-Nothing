NAME = fillit

SRC = sources/check.c \
      sources/go.c \
      sources/main.c \
      sources/tetrislen.c \
	  sources/ft_strsub.c \
	  sources/resolution.c \
	  sources/subfuction.c \
	  sources/addtetris.c \

SRCO = check.o \
	   go.o \
	   main.o \
	   tetrislen.o \
	   ft_strsub.o \
	   resolution.o \
	   subfuction.o \
	   addtetris.o \


INCLUDE = ft.h

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
