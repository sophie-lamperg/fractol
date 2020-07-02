NAME = fractol

HEADER = fractol.h

SRC =	main.c \
        ft_abs.c \
        burningship.c \
        ft_error.c \
        hook.c \
        initial.c \
        julia.c \
        mandelbrot.c \

LIB_PATH = ./libft
LIB_OBJ = $(LIB_PATH:.c=.o)
LIB_SRC = $(LIB_PATH:.c)

MINILIBX_PTH = ./minilibx_macos
MINILIBX_SRC = $(MINILIBX_PTH:.c)
MINILIBX_OBJ = $(MINILIBX_PTH:.c=.o)
MINILIBX_M = $(MINILIBX_PTH:.m=.o)

C_FLAGS = -Wall -Wextra -Werror

FDF_FLAGS = -framework OpenGL -framework AppKit

OBJECTS = $(SRC:.c=.o)

.PHONY: all clean fclean re norma runfractol

all:$(NAME)

$(NAME):$(OBJECTS) $(LIB_OBJ) $(LIB_SRC) $(MINILIBX_OBJ) $(MINILIBX_SRC) $(MINILIBX_M)
	@make -C $(LIB_PATH)
	@make -C $(MINILIBX_PTH)
	@gcc $(C_FLAGS) -c $(SRC)
	@gcc -g $(C_FLAGS) $(OBJECTS) -o $(NAME) -L$(LIB_PATH) -lft -L$(MINILIBX_PTH) $(FDF_FLAGS) -lmlx
clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C $(LIB_PATH)
	@make clean -C $(MINILIBX_PTH)

$(OBJECTS): %.o: %.c $(HEADER)
	gcc $(C_FLAGS) -c $< -o $@

fclean:	clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_PATH)

re:	fclean	all

norma:
	/usr/bin/norminette $(SRC) $(HEADER)
