SRCS = main.c				\
		src/init.c			\
		src/hook.c			\
		src/display.c		\
		src/parse_mapfile.c	\

OBJ = $(SRCS:%c=%o)

NAME = miniRT

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

MAKELIB = cd lib/libft && make -s

LIB = lib/libft/libft.a

MAKELIBX = cd lib/mlx && make -s

LIBX = lib/mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKELIB)
	$(MAKELIBX)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(LIBX) -framework OpenGL -framework AppKit -o $(NAME)

clean:
#	cd lib/libft && make clean -s
	$(RM) $(OBJ)

fclean: clean
	cd lib/libft && make fclean -s
	cd lib/mlx/ && make clean
	$(RM) $(NAME) -s

re: fclean all
