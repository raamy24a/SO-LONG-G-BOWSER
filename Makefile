NAME = so_long

SRC_FILES = srcs/render.c srcs/parsing.c srcs/main.c srcs/input.c srcs/game.c
MLX_FILES = lib/mlx_init.c lib/mlx_new_window.c lib/mlx_pixel_put.c lib/mlx_loop.c \
	lib/mlx_mouse_hook.c lib/mlx_key_hook.c lib/mlx_expose_hook.c lib/mlx_loop_hook.c \
	lib/mlx_int_anti_resize_win.c lib/mlx_int_do_nothing.c \
	lib/mlx_int_wait_first_expose.c lib/mlx_int_get_visual.c \
	lib/mlx_flush_event.c lib/mlx_string_put.c lib/mlx_set_font.c \
	lib/mlx_new_image.c lib/mlx_get_data_addr.c \
	lib/mlx_put_image_to_window.c lib/mlx_get_color_value.c lib/mlx_clear_window.c \
	lib/mlx_xpm.c lib/mlx_int_str_to_wordtab.c lib/mlx_destroy_window.c \
	lib/mlx_int_param_event.c lib/mlx_int_set_win_event_mask.c lib/mlx_hook.c \
	lib/mlx_rgb.c lib/mlx_destroy_image.c lib/mlx_mouse.c lib/mlx_screen_size.c \
	lib/mlx_destroy_display.c

OBJ = $(SRC_FILES:.c=.o)
MLX_OBJ = $(MLX_FILES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -lm
MLXFLAGS =  # No -Werror for MiniLibX
INCLUDES = -Isrcs -Ilib

all: $(NAME)

$(NAME): $(OBJ) $(MLX_OBJ)
	$(CC) $(OBJ) $(MLX_OBJ) -Llib -lXext -lX11 -lm -o $(NAME)

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

lib/%.o: lib/%.c
	$(CC) $(MLXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(MLX_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
