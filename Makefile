NAME = so_long

SRC_FILES = srcs/render.c srcs/parsing.c srcs/main.c srcs/input.c srcs/game.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC_FILES:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
INCLUDES = -Isrcs -Ilib -Ilibft

all: lib/libmlx.a libft/libft.a $(NAME)

$(NAME): $(OBJ) lib/libmlx.a libft/libft.a
	$(CC) $(OBJ) -Llib -lmlx -Llibft -lft -lXext -lX11 -lm -o $(NAME)

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

get_next_line/%.o: get_next_line/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

lib/libmlx.a:
	$(MAKE) -C lib

libft/libft.a:
	$(MAKE) -C libft

clean:
	rm -f $(OBJ)
	$(MAKE) -C lib clean
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C lib clean
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
