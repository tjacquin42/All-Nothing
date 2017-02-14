NAME = fdf

SRC = srcs/main.c \
	  srcs/seg_tracer.c \
	  srcs/print_errors.c \
	  srcs/events_script.c \
	  srcs/send_to_trace.c \
	  srcs/display.c \
	  srcs/more_functions.c \

SRCO = main.o \
	   seg_tracer.o \
	   print_errors.o \
	   events_script.o \
	   send_to_trace.o \
	   display.o \
	   more_functions.o \

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
