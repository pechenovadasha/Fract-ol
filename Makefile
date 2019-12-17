NAME = fractol

SRC  =  mandelbrot.c fractol.c hooks.c julia.c burningship.c initial.c

OBJ  = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -Ofast

OSVER := $(shell uname -s)

ifeq ($(OSVER), Linux)
		LIBFLAGS = -lmlx -lXext -lX11 minilibx/libmlx.a -lm
	else
		LIBFLAGS = -framework OpenGL -framework AppKit -lm -lmlx
	endif

RED= \033[1;31m
GREEN= \033[1;32m
YELLOW= \033[1;33m
BLUE= \033[1;34m
VIOLET= \033[1;35m

all: $(NAME)

$(NAME): $(OBJ)
		gcc $(FLAGS) $(OBJ) $(LIBFLAGS) -o $(NAME)
			@echo "$(GREEN)Project is successfully compiled"

%.o : %.c
		gcc $(FLAGS) -c $< -o $@

clean:
		@echo "$(RED)Suspending library files$(VIOLET)"
			rm -rf *.o
			rm -rf *.gch

fclean: clean
		@echo "$(RED)Suspending project files$(VIOLET)"
			rm -rf $(OBJ)
				rm -rf $(NAME)

re: fclean all
