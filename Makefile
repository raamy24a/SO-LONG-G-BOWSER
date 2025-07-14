NAME = so_long

SRC_FILES = srcs/render.c srcs/parsing.c srcs/main.c srcs/game.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	printf/ft_printf.c printf/ft_putnbr.c

OBJ = $(SRC_FILES:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
INCLUDES = -Isrcs -Ilib -Ilibft

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Llib -lmlx -Llibft -lft -lXext -lX11 -lm -o $(NAME)

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

get_next_line/%.o: get_next_line/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
